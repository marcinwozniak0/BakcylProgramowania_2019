#include "Spell.hpp"
#include <iostream>

Spell::Spell(uint power, std::string name, std::string description, uint manaCost)
   :Card(name, description, manaCost)
   ,_power(power)
{}

uint Spell::getPower() const
{
  return _power;
}
