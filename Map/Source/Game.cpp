#include "Game.hpp"
#include <cctype>

Direction Game::getDirection()
{
    initscr();
    noecho();
    char direction = getch();
    switch(std::tolower(direction))
    {
        case 'w':
            endwin();
            return Direction::Up;
        case 'a':
            endwin();
            return Direction::Left;
        case 's':
            endwin();
            return Direction::Down;
        case 'd':
            endwin();
            return Direction::Right;
        default:
            return getDirection();
    }
}
