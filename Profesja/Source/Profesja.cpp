#include "Profesja.hpp"
#include <iostream>
#include <string>
#include <vector>

void Player :: Paladin :: useUlt(Player& p1, Player& p2)
{
  p1.currentHp += p1.power;
}

void Player :: Mage :: useUlt(Player& p1, Player& p2)
{
  p2.currentHp -= p1.power;
}

void Player :: Rogue :: useUlt(Player& p1, Player& p2)
{
  p1.handdeck.push_back(p2.handdeck.at(0));
  p2.handdeck.erase(p2.handdeck.begin());
}
