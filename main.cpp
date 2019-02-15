#include <iostream>
#include <SFML/Window.hpp>
#include "catch.hpp"
#include "GUIBoard.h"
#define CATCH_CONFIG_MAIN

int main()
{
    GUIBoard board;
    while(board.isOpen())
    {
        board.update();
    }

    return 0;
}