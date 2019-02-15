//
// Created by Mark on 2/14/2019.
//

#include <SFML/Graphics.hpp>

#ifndef CS372_BATTLESHIP_GAME_GUIBOARD_H
#define CS372_BATTLESHIP_GAME_GUIBOARD_H


class GUIBoard
{
public:
    GUIBoard();

    void update();

    bool isOpen();
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite  backgroundSprite;
};


#endif //CS372_BATTLESHIP_GAME_GUIBOARD_H
