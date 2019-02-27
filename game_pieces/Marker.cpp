//
// Created by Mark on 2/21/2019.
//

#include <SFML/Graphics/CircleShape.hpp>
#include <Marker.h>

#include "../include/Marker.h"

Marker::Marker(sf::Vector2i coords, int hit)
{
    _markerSprite.setRadius(26);
    _markerSprite.setPosition(sf::Vector2f(coords));
    if (hit == 1) _markerSprite.setFillColor(sf::Color::Red);
    else if (hit == 2) _markerSprite.setFillColor(sf::Color::Green);
    else _markerSprite.setFillColor(sf::Color::White);
}

void Marker::draw(sf::RenderWindow & window)
{
    window.draw(_markerSprite);
}

sf::Vector2f Marker::getPosition()
{
    return _markerSprite.getPosition();
}
