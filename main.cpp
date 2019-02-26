
#include "catch.hpp"
#include <iostream>
#include <SFML/Window.hpp>
#include "include/GUIBoard.h"

int main()
{
    GUIBoard board1;
    GUIBoard board2;
    int turn = 0;
    while(board1.isOpen() && board2.isOpen())
    {
        if (board1.hasLost())
        {
            board2.wins();
            board1.loses();
            turn = 0;
        }
        else if (board2.hasLost())
        {
            board1.wins();
            board2.loses();
            turn = 0;
        }

        if (turn == 0)
        {
            board1.update();
            board2.update();
        }
        if (board1.shipsPlaced() && board2.shipsPlaced() && turn == 0) turn = 1;

        if (turn == 1)
        {
            board2.update();
            sf::Vector2i coords = board1.makeMove();
            int hit = board2.isHit(coords);
            if(board1.moveMade(coords,hit))
            {
                board1.update();
                board2.update();
                turn = 2;
            }
        }
        else if (turn == 2)
        {
            board1.update();
            sf::Vector2i coords = board2.makeMove();
            int hit = board1.isHit(coords);
            if(board2.moveMade(coords,hit))
            {
                board1.update();
                board2.update();
                turn = 1;
            }
        }
    }

    return 0;
}