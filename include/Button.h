//
// Created by Mark on 2/21/2019.
//

#ifndef CS372_BATTLESHIP_GAME_BUTTON_H
#define CS372_BATTLESHIP_GAME_BUTTON_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <functional>

class Button
{
public:
    Button(int, int);
    void setSkin(std::string);
    void setPosition(int, int);
    void setAction(std::function<void(void)> &&);
    void doAction();
    void draw(sf::RenderWindow&);
    bool click(sf::RenderWindow &);
private:
    sf::RectangleShape _sprite;
    sf::Texture _texture;

    std::function<void(void)> _doAction;
};


#endif //CS372_BATTLESHIP_GAME_BUTTON_H
