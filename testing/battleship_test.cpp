//
// Created by Mark on 2/14/2019.
//

#include "../catch.hpp"
#include "../include/GUIBoard.h"
#include "../include/Button.h"

GUIBoard board;
TEST_CASE("Game Initialization")
{
    REQUIRE(board.isOpen());
    REQUIRE(board.isOpen());
}

TEST_CASE("Button Class")
{
    Button button(100, 50);
    button.setSkin();
    button.setPosition(30, 30);
    int a = 0;

    button.setAction([&](){a = 3;});
    button.doAction();
    REQUIRE(a == 3);

    button.setAction([&](){a+=5;});
    button.doAction();
    REQUIRE(a == 8);
    REQUIRE(true);
}