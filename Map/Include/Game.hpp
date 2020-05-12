#pragma once
#include <ncurses.h>
#include "Map.hpp"
#include "Player.hpp"

class Game
{
public:
    Game(Map& map, Player& player) : _map(map), _player(player) {}
    Direction getDirection();
    void makeMove(const Direction&);

private:
    Map& _map;
    Player& _player;
};
