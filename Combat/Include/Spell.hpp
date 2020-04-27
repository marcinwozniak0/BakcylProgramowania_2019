#pragma once
#include "Card.hpp"
#include <iostream>

class Spell : public Card
{
protected:
   uint _power;
   //virtual void useCard() = 0;
public:
   Spell(uint power, std::string name, std::string description, uint manaCost);
   uint getPower() const;
};
