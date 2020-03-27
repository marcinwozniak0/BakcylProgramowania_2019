#include "ProfessionRogue.hpp"

void Rogue :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  if(p1.has_value()&& p2.has_value())
  {
    srand( time( NULL ) );
    rng = ( std::rand() % p2.value().handdeck.size());
    p1.value().handdeck.push_back(std::move(p2.value().handdeck.at(rng)));
    p2.value().handdeck.erase(p2.value().handdeck.begin() + rng);
  }
  else
  {
    std::cerr << "P1/P2 has no value(Rogue)";
  }
}
