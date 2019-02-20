//
// Created by Mark on 2/14/2019.
//

#include "GUIBoard.h"
#include "game_pieces/Ship.h"
#include <vector>
using std::vector;

GUIBoard::GUIBoard()
{
    _window.create(sf::VideoMode(800, 600), "My window");
    if(!_backgroundTexture.loadFromFile("../textures/board.png")){}
    _backgroundSprite.setTexture(_backgroundTexture);
    _ships.emplace_back(Ship(1,2));
    _ships.emplace_back(Ship(1,3));
    _ships.emplace_back(Ship(1,3));
    _ships.emplace_back(Ship(1,4));
    _ships.emplace_back(Ship(1,5));
}

bool GUIBoard::isOpen()
{
    return _window.isOpen();
}

bool isHeld = false;
sf::Vector2i startPosition(0,0);
void GUIBoard::update()
{
    sf::Event event; // NOLINT(cppcoreguidelines-pro-type-member-init)
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            for (auto &ship : _ships) {
                if (ship.mouseOver(_window) && !isHeld)
                {
                    isHeld = true;
                    startPosition = sf::Mouse::getPosition(_window);
                }
            }
        }
        else
        {
            isHeld = false;
        }

        if (event.type == sf::Event::MouseMoved)
        {
            if (isHeld)
            {
                sf::Vector2i currentPosition = sf::Mouse::getPosition(_window);
                for (auto & ship : _ships)
                {
                    ship.moveShip(currentPosition - startPosition);
                }
                startPosition = currentPosition;
            }
        }

//        if (event.type == sf::Event::MouseButtonReleased)
//        {
//            if (miss())
//            {
//                placeMarker("miss");
//            }
//            else
//            {
//                placeMarker("hit");
//            }
//        }
    }

    _window.clear(sf::Color::Black);
    _window.draw(_backgroundSprite);
    for (auto ship : _ships)
    {
        ship.draw(_window);
    }
    _window.display();
}
