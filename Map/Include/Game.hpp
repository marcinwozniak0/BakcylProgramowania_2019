#pragma once
#include <ncurses.h>
#include "Map.hpp"
#include "Player.hpp"

class Game
{
public:
    Game(Map& map, Player& player) : _map(map), _player(player) {}
    Direction getDirection();

private:
    Map& _map;
    Player& _player;
};
