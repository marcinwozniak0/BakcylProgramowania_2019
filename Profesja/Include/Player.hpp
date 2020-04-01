#pragma once
#include <vector>
#include <string>

class Player
{
public:
  uint currentHp;
  std::vector<std::string> handdeck;
  Player(uint Hp);
};
