#include "HealSpell.hpp"
#include <iostream>

HealSpell::HealSpell(uint power, std::string name, std::string description, uint manaCost)
   :Spell(power, name, description, manaCost)
{}

void HealSpell::heal(Points& hp)
{
   hp.add(_power);
}
