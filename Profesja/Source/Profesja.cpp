#include "Profesja.hpp"

void Paladin :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  uint power = 1;
  p1.currentHp += power;
}

void Mage :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  uint power = 1;
  p2.currentHp -= power;
}

void Rogue :: useUlt(std::optional<Player>& p1, std::optional<Player>& p2)
{
  srand( time( NULL ) );
  rng = ( std::rand() % p2.handdeck.size());
  p1.handdeck.push_back(std::move(p2.handdeck.at(rng)));
  p2.handdeck.erase(p2.handdeck.begin() + rng);
}
