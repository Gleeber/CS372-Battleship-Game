//
// Created by Mark on 2/16/2019.
//

#include <SFML/Graphics.hpp>
#include "Ship.h"

Ship::Ship(int xDim, int yDim)
{
    _shipSprite.setSize(sf::Vector2f((xDim*54), (yDim*54)));
    _shipSprite.setPosition(650.0f, 50.0f);
}

void Ship::draw(sf::RenderWindow &window)
{
    window.draw(_shipSprite);
}

void Ship::moveShip(float x, float y)
{
    _shipSprite.setPosition(x,y);
}

void Ship::moveShip(sf::Vector2i pos)
{
    _shipSprite.move((float)pos.x, (float)pos.y);
}

bool Ship::mouseOver(sf::RenderWindow & window)
{
    return _shipSprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window));
}


