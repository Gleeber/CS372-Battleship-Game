//
// Created by Mark on 2/14/2019.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include "game_pieces/Ship.h"

#ifndef CS372_BATTLESHIP_GAME_GUIBOARD_H
#define CS372_BATTLESHIP_GAME_GUIBOARD_H


class GUIBoard
{
public:
    GUIBoard();

    void update();

    bool isOpen();
private:
    sf::RenderWindow _window;
    sf::Texture _backgroundTexture;
    sf::Sprite  _backgroundSprite;
    std::vector<Ship> _ships;
};


#endif //CS372_BATTLESHIP_GAME_GUIBOARD_H
