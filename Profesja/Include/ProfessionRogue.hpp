#pragma once
#include "Profession.hpp"

class Rogue : public Profession
{
 public:
  uint rng = 0;
  void useUlt(std::optional<Player>& p1, std::optional<Player>& p2) override;
};
