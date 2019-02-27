#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Mark on 2/16/2019.
//

#include <SFML/Graphics.hpp>
#include <Ship.h>

#include "../include/Ship.h"

RegionMap Ship::_regionMap = RegionMap();
int Ship::_shipID = 0;
sf::Texture Ship::_shipTextures = sf::Texture();
std::vector<sf::IntRect> Ship::_partitionedShipTextures =
        {
                sf::IntRect(54*3,0,54,54*2),
                sf::IntRect(54,0,54,54*3),
                sf::IntRect(54*2,0,54,54*3),
                sf::IntRect(0,0,54,54*4),
                sf::IntRect(0,0,54,54*4), //TODO: change when I get the other ship texture
        };

void Ship::_setShipPosition(sf::Vector2f pos)
{
    _shipSprite.setPosition(pos);
}

Ship::Ship(int xDim, int yDim) : _isHeld{false}, _hitsLeft(yDim),
            _startPosition{_regionMap.assignStartPosition(_shipID)}
{
    _shipSprite.setSize(sf::Vector2f((xDim*54), (yDim*54)));

    if (!_shipTextures.loadFromFile("../resources/ships.png")){}

    _setShipPosition(_startPosition);
    ++_shipID;
}

void Ship::draw(sf::RenderWindow &window)
{
    window.draw(_shipSprite);
}

void Ship::rotateShip()
{
    if (_shipSprite.getRotation() == 0.f)
    {
        _shipSprite.setRotation(270.f);
        _shipSprite.move(0,54.f);
    }
    else
    {
        _shipSprite.setRotation(0.f);
        _shipSprite.move(0,-54.f);
    }
}

bool Ship::isSunk()
{
    _hitsLeft--;
    return _hitsLeft == 0;
}

void Ship::moveShip(sf::Vector2i pos)
{
    _shipSprite.move((float)pos.x, (float)pos.y);
}

bool Ship::mouseOver(sf::RenderWindow & window) const
{
    return _shipSprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window));
}

bool Ship::contains(sf::Vector2f position) const
{
    return _shipSprite.getGlobalBounds().contains(position);
}

bool Ship::isHeld() const
{
    return _isHeld;
}

void Ship::setHeld(bool state)
{
    _isHeld = state;
}

bool Ship::onBoard() const
{
    sf::Vector2f shipPosition =  _shipSprite.getPosition();
    sf::Vector2f shipDimensions = _shipSprite.getSize();
    if (_shipSprite.getRotation() == 270.f)
    {
        shipDimensions.x = _shipSprite.getSize().y;
        shipDimensions.y = _shipSprite.getSize().x;
        shipPosition.y -= shipDimensions.y;
    }
    return _regionMap.onBoard(shipPosition, shipDimensions);
}

void Ship::snapToGrid()
{
    sf::Vector2f shipPosition =  _shipSprite.getPosition();

    if(onBoard())
    {
        auto closestSquare = _regionMap.closestSquare(shipPosition);
        if (_shipSprite.getRotation() == 270.f && closestSquare.y == 0)
        {
            closestSquare.y += 54.f;
        }
        _setShipPosition(closestSquare);
    }
    else
    {
        if (_shipSprite.getRotation() == 270.f)
        {
            rotateShip();
        }
        _setShipPosition(_startPosition);
    }
}

sf::IntRect Ship::_assignTextureRect(int shipID)
{
    auto index = shipID % 5;
    return _partitionedShipTextures[index];
}

void Ship::setSkin()
{
    sf::Rect textureRect = _assignTextureRect(_shipID-1);
    _shipSprite.setTexture(&_shipTextures);
    _shipSprite.setTextureRect(textureRect);
}


#pragma clang diagnostic pop