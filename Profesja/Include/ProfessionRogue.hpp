#pragma once
#include "Profession.hpp"

class Rogue : public Profession
{
 public:
  uint rng = 0;
  void useUlt(std::optional<Player>& player1, std::optional<Player>& player2) override;
};
