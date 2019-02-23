//
// Created by Mark on 2/16/2019.
//
#ifndef CS372_BATTLESHIP_GAME_SHIP_H
#define CS372_BATTLESHIP_GAME_SHIP_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../game_board/RegionMap.h"

class Ship
{
public:
    Ship(int, int, int);

    void moveShip(sf::Vector2i);

    void snapToGrid();

    void draw(sf::RenderWindow & window);

    bool isSunk();

    bool mouseOver(sf::RenderWindow &);

    bool contains(sf::Vector2f) const;

    bool isHeld();

    void setHeld(bool);

    bool onBoard() const;
private:
    void _setShipPosition(sf::Vector2f);
    sf::RectangleShape _shipSprite;
    bool _isHeld;
    RegionMap _regionMap;
    int _hitsLeft;
    sf::Vector2f _startPosition;
};


#endif //CS372_BATTLESHIP_GAME_SHIP_H
