#pragma once
#include "Map.hpp"

class Game
{
public:
    Game(Map& map) : _map(map) {}

private:
    Map& _map;
};
