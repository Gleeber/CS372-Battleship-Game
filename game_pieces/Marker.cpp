//
// Created by Mark on 2/21/2019.
//

#include <SFML/Graphics/CircleShape.hpp>
#include "Marker.h"

Marker::Marker(sf::Vector2i coords, bool hit)
{
    _markerSprite.setRadius(26);
    _markerSprite.setPosition(sf::Vector2f(coords));
    _markerSprite.setFillColor(sf::Color::Red);
}

void Marker::draw(sf::RenderWindow & window)
{
    window.draw(_markerSprite);
}
