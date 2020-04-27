#pragma once
#include "Spell.hpp"
#include "Points.hpp"
#include <iostream>

class DamageSpell : public Spell
{
public:
  DamageSpell(uint power, std::string name, std::string description, uint manaCost);
  void damage(Points& hp);
};
