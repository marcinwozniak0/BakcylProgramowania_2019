#include "ProfessionMage.hpp"

void Mage :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  if(p2.has_value() == true)
  {
    uint power = 1;
    p2.value().currentHp -= power;
  }
}
