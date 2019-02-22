//
// Created by Mark on 2/16/2019.
//

#include <SFML/Graphics.hpp>
#include "Ship.h"

void Ship::_setShipPosition(sf::Vector2f pos)
{
    _shipSprite.setPosition(pos);
}

Ship::Ship(int xDim, int yDim, int assignedStartPosition) : _isHeld{false}, _regionMap{},
            _startPosition{_regionMap.assignStartPosition(assignedStartPosition)}
{
    _shipSprite.setSize(sf::Vector2f((xDim*54), (yDim*54)));
    _setShipPosition(_startPosition);
}

void Ship::draw(sf::RenderWindow &window)
{
    window.draw(_shipSprite);
}

sf::Vector2f Ship::getPosition()
{
    return _shipSprite.getPosition();
}

void Ship::moveShip(sf::Vector2i pos)
{
    _shipSprite.move((float)pos.x, (float)pos.y);
}

bool Ship::mouseOver(sf::RenderWindow & window)
{
    return _shipSprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window));
}

bool Ship::isHeld()
{
    return _isHeld;
}

void Ship::setHeld(bool state)
{
    _isHeld = state;
}

bool Ship::onBoard()
{
    sf::Vector2f shipPosition =  _shipSprite.getPosition();
    return _regionMap.onBoard(shipPosition, _shipSprite.getSize().y);
}

void Ship::snapToGrid()
{
    sf::Vector2f shipPosition =  _shipSprite.getPosition();

    if(onBoard())
    {
        _setShipPosition(_regionMap.closestSquare(shipPosition));
    }
    else
    {
        _setShipPosition(_startPosition);
    }
}

