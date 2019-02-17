//
// Created by Mark on 2/16/2019.
//

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
