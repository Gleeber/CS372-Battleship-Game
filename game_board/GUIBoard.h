//
// Created by Mark on 2/14/2019.
//
#ifndef CS372_BATTLESHIP_GAME_GUIBOARD_H
#define CS372_BATTLESHIP_GAME_GUIBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../game_pieces/Ship.h"
#include "../game_pieces/Marker.h"

class GUIBoard
{
public:
    GUIBoard();

    void update();

    sf::Vector2i makeMove();

    bool isHit(sf::Vector2i);

    bool moveMade(sf::Vector2i,bool);

    bool isOpen();

    bool shipsPlaced();
private:
    sf::RenderWindow _window;
    sf::Texture _backgroundTexture;
    sf::Sprite  _backgroundSprite;
    std::vector<Ship> _ships;
    std::vector<Marker> _markers;
    bool _shipsPlaced;
    bool _pieceIsHeld;
};


#endif //CS372_BATTLESHIP_GAME_GUIBOARD_H
