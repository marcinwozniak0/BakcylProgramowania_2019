#include "ProfessionMage.hpp"

void Mage :: useUlt(std::optional<Player>& player1, std::optional<Player>& player2) try
{
  if(player2.has_value())
  {
    constexpr uint damagePower = 1;
    player2.value()._HP.remove(damagePower);
  }
  else
  {
    throw std::out_of_range("Invalid value");
  }
}
catch (std::out_of_range& exception)
{
  std::cout << exception.what();
}
