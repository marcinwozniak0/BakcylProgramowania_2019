#include "Profesja.hpp"

void Paladin :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  if(p1.has_value() == true)
  {
    uint power = 1;
    p1.value().currentHp += power;
  }
}

void Mage :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  if(p2.has_value() == true)
  {
    uint power = 1;
    p2.value().currentHp -= power;
  }
}

void Rogue :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  if(p1.has_value() == true && p2.has_value() == true)
  {
    srand( time( NULL ) );
    rng = ( std::rand() % p2.value().handdeck.size());
    p1.value().handdeck.push_back(std::move(p2.value().handdeck.at(rng)));
    p2.value().handdeck.erase(p2.value().handdeck.begin() + rng);
  }
}
