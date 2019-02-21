//
// Created by Mark on 2/19/2019.
//
#ifndef CS372_BATTLESHIP_GAME_REGIONMAP_H
#define CS372_BATTLESHIP_GAME_REGIONMAP_H

#include <vector>
#include <SFML/System/Vector2.hpp>

class RegionMap
{
public:
    RegionMap();
    sf::Vector2f closestSquare(sf::Vector2f);
    bool onBoard(sf::Vector2f, float);
    sf::Vector2f assignStartPosition(int);
private:
    void _populateGridWithCoordinates();
    float _distance(sf::Vector2f, sf::Vector2f);
    std::vector<sf::Vector2f> _grid;
    std::vector<sf::Vector2f> _startPositions;
};


#endif //CS372_BATTLESHIP_GAME_REGIONMAP_H
