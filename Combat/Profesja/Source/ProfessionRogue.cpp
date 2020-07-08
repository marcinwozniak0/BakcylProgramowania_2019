#include "ProfessionRogue.hpp"
#include <iostream>

void Rogue :: useUlt(std::optional<Player>& player1, std::optional<Player>& player2) try
{
  if(player1.has_value()&& player2.has_value())
  {
    srand( time( NULL ) );
    rng = ( std::rand() % (player2.value()._playersHanddeck.getSize()));
    player1.value()._playersHanddeck.addCard(std::move(player2.value()._playersHanddeck.cards->at(rng)));
    player2.value()._playersHanddeck.removeCard(player2.value()._playersHanddeck.cards->at(rng));
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
