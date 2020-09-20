#include <iostream>
#include "Game.hpp"

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

void Game::makeMove(const Direction& direction)
{
    bool isMovePossible = _map.isMovePossible(_player.getCurrentPosition(), direction);

    if(isMovePossible)
    {
        Position newPosition = _player.getCurrentPosition();

        switch(direction)
        {
            case Direction::Up:
            {
                ++newPosition._y;
                break;
            }
            case Direction::Down:
            {
                --newPosition._y;
                break;
            }

            case Direction::Left:
            {
                --newPosition._x;
                break;
            }
            case Direction::Right:
            {
                ++newPosition._x;
                break;
            }
        }

        _player.setNewPosition(newPosition);
        _map.getFields().at(newPosition._x).at(newPosition._y) -> action();
        _map.makeFieldEmpty(newPosition);
        std::string map = _map.getMapToPrint(newPosition);
        std::cout << map << std::endl;
    }
}
