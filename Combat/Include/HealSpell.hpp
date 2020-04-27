#pragma once
#include "Spell.hpp"
#include "Points.hpp"
#include <iostream>

class HealSpell : public Spell
{
public:
   HealSpell(uint power, std::string name, std::string description, uint manaCost);
   void heal(Points& hp);
};
