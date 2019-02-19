

#include "catch.hpp"
#include <iostream>
#include <SFML/Window.hpp>
#include "GUIBoard.h"

int main()
{
    GUIBoard board1;
    GUIBoard board2;
    while(board1.isOpen() && board2.isOpen())
    {
        board1.update();
        board2.update();
    }

    return 0;
}