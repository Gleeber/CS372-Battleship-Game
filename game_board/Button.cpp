//
// Created by Mark on 2/21/2019.
//

#include "Button.h"
#include <functional>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Texture.hpp>

Button::Button(int width, int height)
{
    _sprite.setSize(sf::Vector2f(width, height));
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

void Button::draw(sf::RenderWindow & window)
{
    window.draw(_sprite);
}

bool Button::click(sf::RenderWindow & window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    const sf::FloatRect buttonBounds = _sprite.getGlobalBounds();
    return buttonBounds.contains(mousePosition.x, mousePosition.y);
}

void Button::setSkin(std::string skin)
{
    if (!_texture.loadFromFile("../textures/" + skin)){}
    _sprite.setTexture(&_texture);
}
