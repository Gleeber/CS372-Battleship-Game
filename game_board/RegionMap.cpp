//
// Created by Mark on 2/19/2019.
//

#include "RegionMap.h"
#include <vector>
#include <cmath>
#include <algorithm>

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
    std::vector<float> distances;
    for (auto gridSquare : _boardGrid)
    {
        distances.push_back(_distance(shipPosition, gridSquare));
    }



    return sf::Vector2i(0,0);
}

