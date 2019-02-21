//
// Created by Mark on 2/19/2019.
//

#include "RegionMap.h"
#include <map>
#include <cmath>
#include <algorithm>

void RegionMap::_populateGrid()
{
    for (auto row = 0; row < 10; ++row)
    {
        for (auto column = 0; column < 10; ++column)
        {
            _boardGrid.emplace_back(62.f + column*54.f, row*54.f);
        }
    }
}

RegionMap::RegionMap()
{
    _populateGrid();
}

bool RegionMap::onBoard(sf::Vector2f shipPosition)
{
    return shipPosition.x < 600;
}

float RegionMap::_distance(sf::Vector2f shipSquare, sf::Vector2f gridSquare)
{
    float diffX = shipSquare.x - gridSquare.x;
    float diffY = shipSquare.y - gridSquare.y;
    return std::sqrt(diffX*diffX + diffY*diffY);
}

sf::Vector2i RegionMap::closestSquare(sf::Vector2f shipPosition)
{
    std::map<float, sf::Vector2f> distances;
    for (auto gridSquare : _boardGrid)
    {
        distances[_distance(shipPosition, gridSquare)] = gridSquare;
    }

    const auto [smallestDistance, squareCoords] = *std::min_element(begin(distances), end(distances),
                                                [] (auto a, auto b){return a.first < b.first;});

    return sf::Vector2i((int)squareCoords.x, (int)squareCoords.y);
}





