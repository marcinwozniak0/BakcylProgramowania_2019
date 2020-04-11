#pragma once
#include <vector>
#include <string>
#include "Points.hpp"

class Player
{
public:
  Points _hp;
  Points _mp;
  std::vector<std::string> handdeck;
  Player(Points hp, Points mp);
};
