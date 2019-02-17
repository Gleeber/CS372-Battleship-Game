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

    void draw(sf::RenderWindow & window);
private:
    //map<std::string, int> _coordinates;
    sf::RectangleShape _shipSprite;
};


#endif //CS372_BATTLESHIP_GAME_SHIP_H
