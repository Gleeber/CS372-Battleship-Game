//
// Created by Mark on 2/16/2019.
//
#ifndef CS372_BATTLESHIP_GAME_SHIP_H
#define CS372_BATTLESHIP_GAME_SHIP_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "RegionMap.h"

class Ship
{
public:
    Ship(int, int);

    void moveShip(sf::Vector2i);

    void snapToGrid();

    void rotateShip();

    void draw(sf::RenderWindow & window);

    bool isSunk();

    bool mouseOver(sf::RenderWindow &) const;

    bool contains(sf::Vector2f) const;

    bool isHeld() const;

    void setHeld(bool);

    bool onBoard() const;

    void setSkin();
private:
    void _setShipPosition(sf::Vector2f);
    sf::RectangleShape _shipSprite;
    static sf::Texture _shipTextures;
    static std::vector<sf::IntRect> _partitionedShipTextures;
    sf::IntRect _assignTextureRect(int);
    bool _isHeld;
    static RegionMap _regionMap;
    static int _shipID;
    int _hitsLeft;
    sf::Vector2f _startPosition;
};


#endif //CS372_BATTLESHIP_GAME_SHIP_H
