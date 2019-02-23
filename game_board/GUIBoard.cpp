//
// Created by Mark on 2/14/2019.
//

#include "GUIBoard.h"
#include "../game_pieces/Ship.h"
#include "RegionMap.h"
#include <vector>

using std::vector;

GUIBoard::GUIBoard() : _pieceIsHeld{false}, _shipsPlaced{false}
{
    _window.create(sf::VideoMode(600+600+200, 600), "My window");
    if(!_backgroundTexture.loadFromFile("../textures/board.png")){}

    _playerBoard.setTexture(_backgroundTexture);
    _playerBoard.setPosition(0.f,0.f);

    _enemyBoard.setTexture(_backgroundTexture);
    _enemyBoard.setTextureRect(sf::IntRect(0,0,600,600));
    _enemyBoard.setPosition(800.f,0.f);

    _ships.emplace_back(Ship(1, 2, 0));
    _ships.emplace_back(Ship(1, 3, 1));
    _ships.emplace_back(Ship(1, 3, 2));
    _ships.emplace_back(Ship(1, 4, 3));
    _ships.emplace_back(Ship(1, 5, 4));
}

bool GUIBoard::isOpen()
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
            if (!_shipsPlaced)
            {
                _pickUpShip(startPosition);
            }
        }
        else
        {
            _releaseShips();
        }

        if (event.type == sf::Event::MouseMoved)
        {
            _moveHeldShip(startPosition);
        }

        if (event.type == sf::Event::MouseButtonReleased)
        {
            _dropHeldShip();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            _lockShipsInPlace();
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
    _window.display();
}

void GUIBoard::_lockShipsInPlace()
{//_shipsPlaced = true;
    for (const auto & ship : _ships)
            {
                if (!ship.onBoard()) _shipsPlaced = false;
            }
    _shipsPlaced = true;
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
    for (auto ship = std::begin(_ships); ship != std::end(_ships); ship++)
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

bool GUIBoard::shipsPlaced()
{
    return _shipsPlaced;
}
