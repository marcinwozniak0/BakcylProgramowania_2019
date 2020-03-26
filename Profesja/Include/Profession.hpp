#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <optional>
#include "Player.hpp"

class Profession
{
 public:
  virtual void useUlt(std::optional<Player>& p1, std::optional<Player>& p2) = 0;
};
