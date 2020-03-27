#pragma once
#include "Profession.hpp"

class Mage : public Profession
{
 public:
  void useUlt(std::optional<Player>& p1, std::optional<Player>& p2) override;
};
