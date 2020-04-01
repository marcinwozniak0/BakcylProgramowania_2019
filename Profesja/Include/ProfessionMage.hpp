#pragma once
#include "Profession.hpp"

class Mage : public Profession
{
 public:
  void useUlt(std::optional<Player>& player1, std::optional<Player>& player2) override;
};
