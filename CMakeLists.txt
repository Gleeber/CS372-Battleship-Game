cmake_minimum_required(VERSION 3.13)
project(CS372_Battleship_Game)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")

add_executable(CS372_Battleship_Game main.cpp game_board/GUIBoard.cpp game_pieces/Ship.cpp game_board/RegionMap.cpp game_pieces/Marker.cpp Button.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(CS372_Battleship_Game ${SFML_LIBRARIES})
endif()