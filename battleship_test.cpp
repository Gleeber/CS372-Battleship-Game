//
// Created by Mark on 2/14/2019.
//

#include "catch.hpp"
#include "GUIBoard.h"

GUIBoard board;
TEST_CASE("Game Initialization")
{
    REQUIRE(board.isOpen());
    REQUIRE(board.isOpen());
}