//
// Created by Mark on 2/16/2019.
//

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#ifndef CS372_BATTLESHIP_GAME_SHIP_H
#define CS372_BATTLESHIP_GAME_SHIP_H


class Ship
{
public:
    Ship(int, int);

    void moveShip(float x, float y);

    void moveShip(sf::Vector2i);

    void draw(sf::RenderWindow & window);

    bool mouseOver(sf::RenderWindow &);

    bool isHeld();

    void setHeld(bool);
private:
    sf::RectangleShape _shipSprite;
    bool _isHeld;
};


#endif //CS372_BATTLESHIP_GAME_SHIP_H
