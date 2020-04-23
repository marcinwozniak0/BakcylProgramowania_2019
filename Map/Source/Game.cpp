#include "Game.hpp"

Map::Direction Game::getDirection()
{
    initscr();
    noecho();
    char direction = getch();
    switch(direction)
    {
        case 'W':
        case 'w':
            return Map::Direction::Up;
        case 'A':
        case 'a':
            return Map::Direction::Left;
        case 'S':
        case 's':
            return Map::Direction::Down;
        case 'D':
        case 'd':
            return Map::Direction::Right;
        default:
            break;
    }
}