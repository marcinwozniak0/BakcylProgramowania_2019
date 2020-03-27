#include "ProfessionPaladin.hpp"

void Paladin :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  if(p1.has_value())
  {
    constexpr uint heal_power = 1;
    p1.value().currentHp += heal_power;
  }
  else
  {
    std::cerr << "P1 has no value(Paladin)";
  }
}
