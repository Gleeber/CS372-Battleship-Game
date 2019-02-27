//
// Created by Mark on 2/14/2019.
//

#include "GUIBoard.h"
#include "../include/Ship.h"
#include "RegionMap.h"
#include "Button.h"
#include <vector>
#include <algorithm>

using std::vector;

GUIBoard::GUIBoard() : _pieceIsHeld{false}, _allShipsOnBoard{false}, _hasLost{false}, _hasWon{false}
{
    _window.create(sf::VideoMode(600+600+200, 600), "My window");
    if(!_backgroundTexture.loadFromFile("../resources/board.png")){}

    _playerBoard.setTexture(_backgroundTexture);
    _playerBoard.setPosition(0.f,0.f);

    _enemyBoard.setTexture(_backgroundTexture);
    _enemyBoard.setTextureRect(sf::IntRect(0,0,600,600));
    _enemyBoard.setPosition(800.f,0.f);

    _ships.emplace_back(Ship(1, 2));
    _ships.back().setSkin();
    _ships.emplace_back(Ship(1, 3));
    _ships.back().setSkin();
    _ships.emplace_back(Ship(1, 3));
    _ships.back().setSkin();
    _ships.emplace_back(Ship(1, 4));
    _ships.back().setSkin();
    _ships.emplace_back(Ship(1, 5));
    _ships.back().setSkin();

    _buttons.emplace_back(Button(100,50));
    _buttons.back().setSkin("lock-ship-button.png");
    _buttons.back().setPosition(700, 522);
    _buttons.back().setAction([this](){_lockShipsInPlace();});

}

bool GUIBoard::isOpen() const
{
    return _window.isOpen();
}

void GUIBoard::update()
{
    static sf::Vector2i startPosition(0,0);
    sf::Event event; // NOLINT(cppcoreguidelines-pro-type-member-init)
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (!_allShipsOnBoard)
            {
                _pickUpShip(startPosition);
            }

            for (auto & button : _buttons)
            {
                if(button.click(_window))
                {
                    button.doAction();
                }
            }

        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
            for (auto &ship : _ships)
            {
                if (ship.mouseOver(_window) && !ship.isHeld())
                {
                    if (ship.onBoard())
                    {
                        ship.rotateShip();
                    }
                }
            }
        }

        if (event.type == sf::Event::MouseMoved)
        {
            _moveHeldShip(startPosition);
        }

        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                _releaseShips();
                _dropHeldShip();
            }
        }
    }

    _window.clear(sf::Color::Black);
    _window.draw(_playerBoard);
    _window.draw(_enemyBoard);
    for (auto ship : _ships)
    {
        ship.draw(_window);
    }
    for (auto marker : _markers)
    {
        marker.draw(_window);
    }
    for (auto & button : _buttons)
    {
        button.draw(_window);
    }

    if (_hasLost)
    {
        _printMessage("YOU LOSE!");
    }
    else if (_hasWon)
    {
        _printMessage("YOU WIN!");
    }

    _window.display();
}

void GUIBoard::_lockShipsInPlace()
{
    if (std::all_of(begin(_ships), end(_ships), [](Ship s){return s.onBoard();}))
    {
        _allShipsOnBoard = true;
    }
}

void GUIBoard::_dropHeldShip()
{
    for(auto &ship : _ships)
    {
       ship.snapToGrid();
    }
}

void GUIBoard::_moveHeldShip(sf::Vector2i & startPosition)
{
    sf::Vector2i currentPosition = sf::Mouse::getPosition(_window);
    for (auto & ship : _ships)
            {
                if (ship.isHeld())
                {
                    ship.moveShip(currentPosition - startPosition);
                    break;
                }
            }
    startPosition = currentPosition;
}

void GUIBoard::_pickUpShip(sf::Vector2i & startPosition)
{
    for (auto &ship : _ships)
    {
        if (ship.mouseOver(_window) && !ship.isHeld() && !_pieceIsHeld)
        {
            _pieceIsHeld = true;
            ship.setHeld(true);
            startPosition = sf::Mouse::getPosition(_window);
            break;
        }
    }
}

void GUIBoard::_releaseShips()
{
    _pieceIsHeld = false;
    for (auto & ship : _ships)
    {
        ship.setHeld(false);
    }
}

sf::Vector2i GUIBoard::makeMove()
{
    sf::Event event; // NOLINT(cppcoreguidelines-pro-type-member-init)
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
        }

        if (event.type == sf::Event::MouseButtonReleased)
        {
            RegionMap regionMap;
            sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
            if (regionMap.onEnemyBoard(sf::Vector2f(mousePos)))
            {
                sf::Vector2f gridPos = regionMap.currentSquare(sf::Vector2f(mousePos));
                if (std::count_if(begin(_markers), end(_markers),
                                  [gridPos](Marker m){return m.getPosition() == gridPos;}) != 0)
                {
                    continue;
                }
                return sf::Vector2i(gridPos);
            }
        }
    }
    return sf::Vector2i();
}

int GUIBoard::isHit(sf::Vector2i coords)
{
    int result = 0;
    coords.x -= 800;
    for (auto ship = std::begin(_ships); ship < std::end(_ships); ship++)
    {
        if ((*ship).contains(sf::Vector2f(coords)))
        {
            if ((*ship).isSunk())
            {
                _ships.erase(ship);
                result++;
            }
            result++;
        }
    }
    return result;
}

bool GUIBoard::moveMade(sf::Vector2i coords, int hit)
{
    sf::Vector2i empty;
    if (coords == empty) return false;
    else
    {
        _markers.emplace_back(Marker(coords,hit));
        return true;
    }
}

bool GUIBoard::allShipsOnBoard() const
{
    return _allShipsOnBoard;
}

bool GUIBoard::hasLost() const
{
    return _ships.empty() && _allShipsOnBoard;
}

void GUIBoard::wins()
{
    _hasWon = true;
}

void GUIBoard::loses()
{
    _hasLost = true;
}

void GUIBoard::_printMessage(std::string message)
{
    sf::RectangleShape background(sf::Vector2f(200,100));
    background.setPosition(600,250);
    background.setFillColor(sf::Color(181,186,179,255));
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(3.f);
    sf::Font font;
    if (!font.loadFromFile("../resources/machinestd.otf")){}
    sf::Text displayedText;
    displayedText.setFont(font);
    displayedText.setFillColor(sf::Color::Black);
    displayedText.setString(message);
    displayedText.setPosition(615,275);
    _window.draw(background);
    _window.draw(displayedText);
}