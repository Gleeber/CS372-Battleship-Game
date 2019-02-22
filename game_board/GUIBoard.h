//
// Created by Mark on 2/14/2019.
//
#ifndef CS372_BATTLESHIP_GAME_GUIBOARD_H
#define CS372_BATTLESHIP_GAME_GUIBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../game_pieces/Ship.h"

class GUIBoard
{
public:
    GUIBoard();

    void update();

    bool isOpen();

    bool shipsPlaced();
private:
    sf::RenderWindow _window;
    sf::Texture _backgroundTexture;
    sf::Sprite  _backgroundSprite;
    std::vector<Ship> _ships;
    bool _shipsPlaced;
    bool _pieceIsHeld;
};


#endif //CS372_BATTLESHIP_GAME_GUIBOARD_H
