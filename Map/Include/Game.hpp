#pragma once
#include <ncurses.h>
#include "Map.hpp"

class Game
{
public:
    Game(Map& map) : _map(map) {}
    Direction getDirection();
    
    void play();

private:
    Map& _map;
    bool _isRunning;
};