//
// Created by Mark on 2/21/2019.
//

#ifndef CS372_BATTLESHIP_GAME_MARKER_H
#define CS372_BATTLESHIP_GAME_MARKER_H

#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Marker
{
public:
    Marker(sf::Vector2i,int);

    void draw(sf::RenderWindow &);

private:
    sf::CircleShape _markerSprite;
};


#endif //CS372_BATTLESHIP_GAME_MARKER_H
