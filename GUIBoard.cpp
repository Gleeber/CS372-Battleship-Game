//
// Created by Mark on 2/14/2019.
//

#include "GUIBoard.h"

GUIBoard::GUIBoard()
{
    window.create(sf::VideoMode(800, 600), "My window");
    if(!backgroundTexture.loadFromFile("../textures/test_image.png")){}
    backgroundSprite.setTexture(backgroundTexture);
}

bool GUIBoard::isOpen()
{
    return window.isOpen();
}

void GUIBoard::update()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.draw(backgroundSprite);

    window.display();
}
