//
// Created by Mark on 2/19/2019.
//

#include "RegionMap.h"
#include <map>
#include <cmath>
#include <algorithm>

void RegionMap::_populateGridWithCoordinates()
{
    for (auto row = 0; row < 10; ++row)
    {
        for (auto column = 0; column < 10; ++column)
        {
            _grid.emplace_back(62.f + column*54.f, row*54.f);
        }
    }
}

RegionMap::RegionMap()
{
    _populateGridWithCoordinates();

    _shipStartPositions = {sf::Vector2f(630.f, 30.f), sf::Vector2f(714.f, 30.f), sf::Vector2f(630.f,168.f), sf::Vector2f(630.f,360.f), sf::Vector2f(714.f,306.f)};
}

bool RegionMap::onBoard(sf::Vector2f shipPosition, float shipLength) const
{
    return shipPosition.x < 600 && (shipPosition.y + shipLength) < 566;
}

bool RegionMap::onEnemyBoard(sf::Vector2f position)
{
    return position.x > 800+62 && position.y < 600-62;
}

float RegionMap::_distance(sf::Vector2f shipSquare, sf::Vector2f gridSquare) const
{
    float diffX = shipSquare.x - gridSquare.x;
    float diffY = shipSquare.y - gridSquare.y;
    return std::sqrt(diffX*diffX + diffY*diffY);
}

sf::Vector2f RegionMap::closestSquare(sf::Vector2f shipPosition) const
{
    std::map<float, sf::Vector2f> distanceToGridSquares;
    for (auto gridSquare : _grid)
    {
        distanceToGridSquares[_distance(shipPosition, gridSquare)] = gridSquare;
    }

    const auto [smallestDistance, squareCoords] = *std::min_element(begin(distanceToGridSquares), end(distanceToGridSquares), [] (auto a, auto b){return a.first < b.first;});

    return sf::Vector2f(squareCoords);
}

sf::Vector2f RegionMap::currentSquare(sf::Vector2f position)
{
    float xPos = position.x - fmod((position.x-2*62.f-200.f),54.f);
    float yPos = position.y - fmod(position.y,54.f);
    return sf::Vector2f(xPos,yPos);
}

sf::Vector2f RegionMap::assignStartPosition(int assignedStartPosition)
{
    return _shipStartPositions[assignedStartPosition];
}






