#include "Spell.hpp"
#include <iostream>

Spell::Spell(int power, std::string name, uint id, std::string description, uint manaCost)
   :Card(name, id, description, manaCost)
   ,_power(power)
{}

void Spell::Execute(Points& other)
{
  if(_power == 0)
  {
     //  funkcyjne spelle
  }
  else
  {
     other.add(_power);
  }
}

int Spell::getPower() const
{
  return _power;
}
