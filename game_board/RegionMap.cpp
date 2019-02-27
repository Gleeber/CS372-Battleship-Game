//
// Created by Mark on 2/19/2019.
//

#include "../include/RegionMap.h"
#include <map>
#include <cmath>
#include <algorithm>

void RegionMap::_populateGridWithCoordinates()
{
    for (auto row = 0; row < 11; ++row)
    {
        for (auto column = 0; column < 10; ++column)
        {
            _grid.emplace_back(_sideBarWidth + column*_gridSquareWidth, row*_gridSquareWidth);
        }
    }
}

RegionMap::RegionMap() : _windowWidth{1400}, _windowHeight{600}, _gridLeftBound{62}, _gridRightBound{600}, _enemyBoardLeftBound{800},
                        _gridSquareWidth{54}, _sideBarWidth{62}, _shipDockWidth{200}
{
    _populateGridWithCoordinates();

    _shipStartPositions = {sf::Vector2f(630.f, 30.f), sf::Vector2f(714.f, 30.f), sf::Vector2f(630.f,168.f), sf::Vector2f(630.f,360.f), sf::Vector2f(714.f,222.f)};
}

bool RegionMap::onBoard(sf::Vector2f shipPosition, sf::Vector2f shipDimensions) const
{
    auto shipWidth = shipDimensions.x;
    auto shipHeight = shipDimensions.y;
    return shipPosition.x < _gridRightBound &&
          (shipPosition.x + shipWidth - shipHeight/2) < _gridRightBound &&
          (shipPosition.y + shipHeight) < 566;
}

bool RegionMap::onEnemyBoard(sf::Vector2f position) const
{
    return position.x > _enemyBoardLeftBound+_sideBarWidth && position.y < _windowHeight-_sideBarWidth;
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
    auto xPos = static_cast<float>(position.x - fmod((position.x - 2 * _sideBarWidth - _shipDockWidth),
            _gridSquareWidth));
    auto yPos = static_cast<float>(position.y - fmod(position.y, _gridSquareWidth));
    return sf::Vector2f(xPos,yPos);
}

sf::Vector2f RegionMap::assignStartPosition(int assignedStartPosition) const
{
    return _shipStartPositions[assignedStartPosition];
}






