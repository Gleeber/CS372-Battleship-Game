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
    Ship(int, int);

    void moveShip(sf::Vector2i);

    void snapToGrid();

    void draw(sf::RenderWindow & window);

    bool mouseOver(sf::RenderWindow &);

    bool isHeld();

    void setHeld(bool);
private:
    void _setShipPosition(sf::Vector2i);
    sf::RectangleShape _shipSprite;
    bool _isHeld;
    RegionMap _regionMap;
};


#endif //CS372_BATTLESHIP_GAME_SHIP_H
