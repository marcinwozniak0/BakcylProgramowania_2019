#pragma once
#include "Card.hpp"
#include "Points.hpp"
#include <string>


class Monster: public Card
{
public:
   Points _hp;
   Points _strength;
   enum class State {active, inactive};
   State _state;

   Monster(Points hp, Points strength, std::string name = "", std::string description = "", uint manaCost = 0, uint cardID = 00);
   void activateCard();
   void dealDamage(Points& hp1, uint amount);
};
