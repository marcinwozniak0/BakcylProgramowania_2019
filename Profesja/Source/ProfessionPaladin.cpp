#include "ProfessionPaladin.hpp"

void Paladin :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  if(p1.has_value() == true)
  {
    uint power = 1;
    p1.value().currentHp += power;
  }
}
