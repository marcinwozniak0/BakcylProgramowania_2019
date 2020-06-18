#pragma once
#include "Player.hpp"
#include <vector>
#include <string>

using Deck = std::vector<std::string>;

class GameControler
{
void init();
void action();
void cleanup();
};
