#include "ProfessionPaladin.hpp"

void Paladin :: useUlt(std::optional<Player>& player1, std::optional<Player>& player2) try
{
  if(player1.has_value())
  {
    constexpr uint healPower = 1;
    player1.value()._hp.add(healPower);
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
