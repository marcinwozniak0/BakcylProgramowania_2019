#pragma once
#include "Card.hpp"
#include <iostream>

class Spell : public Card
{
   public:
      uint power;
      virtual void useCard() = 0;
};
//TODO write subclasses (damageSpell, healingSpell ...)
