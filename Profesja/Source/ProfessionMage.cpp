#include "ProfessionMage.hpp"

void Mage :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  if(p2.has_value())
  {
    constexpr uint damage_power = 1;
    p2.value().currentHp -= damage_power;
  }
  else
  {
    std::cerr << "P2 has no value(Mage)";
  }
}
