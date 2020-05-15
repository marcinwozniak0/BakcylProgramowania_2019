#pragma once
#include "Card.hpp"
#include "Points.hpp"
#include <iostream>

class Spell : public Card
{
protected:
   int _power;
public:
   void Execute(Points& other);
   Spell(int power, std::string name, uint id, std::string description, uint manaCost);
   int getPower() const;
};
