//
// Created by Mark on 2/21/2019.
//

#include "include/Button.h"
#include <functional>

Button::Button(int width, int height)
{
    _sprite.setSize(sf::Vector2f(width, height));
}

void Button::setSkin()
{
//    _sprite.setTexture();
}

void Button::setPosition(int x, int y)
{
    _sprite.setPosition(sf::Vector2f(x,y));
}

void Button::setAction(std::function<void(void)> && action)
{
    _doAction = action;
}

void Button::doAction()
{
    _doAction();
}
