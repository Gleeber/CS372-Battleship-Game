//
// Created by Mark on 2/21/2019.
//

#ifndef CS372_BATTLESHIP_GAME_BUTTON_H
#define CS372_BATTLESHIP_GAME_BUTTON_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

class Button
{
public:
    Button(int, int);
    void setSkin();
    void setPosition(int, int);
    void setAction(std::function<void(void)> &&);
    void doAction();
private:
    sf::RectangleShape _sprite;

    std::function<void(void)> _doAction;
};


#endif //CS372_BATTLESHIP_GAME_BUTTON_H
