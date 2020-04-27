#include "DamageSpell.hpp"
#include <iostream>

DamageSpell::DamageSpell(uint power, std::string name, std::string description, uint manaCost)
   :Spell(power, name, description, manaCost)
{}

void DamageSpell::damage(Points& hp)
{
  hp.remove(_power);
}
