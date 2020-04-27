#include "Monster.hpp"
#include "Points.hpp"
#include <iostream>

Monster::Monster(Points hp, Points strength, std::string name, std::string description, uint manaCost)
   :Card(name, description, manaCost)
   ,_hp(hp)
   ,_strength(strength)
   ,_state(State::inactive)
{}

void Monster::activateCard()
{
   _state = State::active;
}

State Monster::getState() const
{
   return _state;
}

Points Monster::getHp() const
{
   return _hp;
}

void Monster::setHp(Points hp)
{
   _hp = hp;
}

Points Monster::getStrength() const
{
  return _strength;
}

void Monster::setStrength(Points strength)
{
  _strength = strength;
}
