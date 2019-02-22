

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
            sf::Vector2i coords = board1.makeMove();
            bool hit = board2.isHit(coords);
            if(board1.moveMade(coords,hit)) turn = 2;
        }
        else if (turn == 2)
        {
            sf::Vector2i coords = board2.makeMove();
            bool hit = board1.isHit(coords);
            if(board2.moveMade(coords,hit)) turn = 1;
        }
    }

    return 0;
}