//
// Created by Mark on 2/14/2019.
//
#ifndef CS372_BATTLESHIP_GAME_GUIBOARD_H
#define CS372_BATTLESHIP_GAME_GUIBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ship.h"
#include "Marker.h"

class GUIBoard
{
public:
    GUIBoard();

    void update();

    sf::Vector2i makeMove();

    int isHit(sf::Vector2i);

    bool moveMade(sf::Vector2i,int);

    bool isOpen() const;

    bool shipsPlaced() const;

    bool hasLost() const;

    void wins();

    void loses();

private:
    sf::RenderWindow _window;
    sf::Texture _backgroundTexture;
    sf::Sprite  _playerBoard;
    sf::Sprite _enemyBoard;

    std::vector<Ship> _ships;
    std::vector<Marker> _markers;

    bool _shipsPlaced;
    bool _pieceIsHeld;
    bool _hasWon;
    bool _hasLost;

    void _releaseShips();
    void _pickUpShip(sf::Vector2i &);
    void _moveHeldShip(sf::Vector2i &);
    void _dropHeldShip();
    void _lockShipsInPlace();
    void _printMessage(std::string);
};


#endif //CS372_BATTLESHIP_GAME_GUIBOARD_H
