

#include "catch.hpp"
#include <iostream>
#include <SFML/Window.hpp>
#include "game_board/GUIBoard.h"

int main()
{
    GUIBoard board1;
    GUIBoard board2;
    int turn = 0;
    while(board1.isOpen() && board2.isOpen())
    {
        board1.update();
        board2.update();
        if (board1.shipsPlaced() && board2.shipsPlaced() && turn == 0) turn = 1;

        if (turn == 1)
        {
            // turn 1 stuff
            turn = 2;
        }
        else if (turn == 2)
        {
            // turn 2 stuff
            turn = 1;
        }
    }

    return 0;
}