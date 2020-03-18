#include "Profesja.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void Player :: Paladin :: useUlt(this, Player& p2)
{
  uint power = 1;
  p1.currentHp += p1.power;
}

void Player :: Mage :: useUlt(this, Player& p2)
{
  uint power = 1;
  p2.currentHp -= p1.power;
}

void Player :: Rogue :: useUlt(this, Player& p2)
{
  srand( time( NULL ) );
  uint rng = ( std::rand() % 3 );
  p1.handdeck.push_back(p2.handdeck.at(rng));
  p2.handdeck.erase(p2.handdeck.at(rng));
}
