#include "ProfessionRogue.hpp"

void Rogue :: useUlt(std::optional<Player>& player1, std::optional<Player>& player2) try
{
  if(player1.has_value()&& player2.has_value())
  {
    srand( time( NULL ) );
    rng = ( std::rand() % player2.value().handdeck.size());
    player1.value().handdeck.push_back(std::move(player2.value().handdeck.at(rng)));
    player2.value().handdeck.erase(player2.value().handdeck.begin() + rng);
  }
  else
  {
    throw std::out_of_range("Invalid value");
  }
}

catch(std::out_of_range exception)
{
  std::cout << exception.what();
}
