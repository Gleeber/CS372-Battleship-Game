#include <iostream>
#include <SFML/Window.hpp>
#include "catch.hpp"
#include "GUIBoard.h"
#define CATCH_CONFIG_RUNNER

int main()
{
    GUIBoard board1;
    GUIBoard board2;
    while(board1.isOpen())
    {
        board1.update();
        board2.update();
    }

    return 0;
}