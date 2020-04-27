#pragma once
#include "Card.hpp"
#include "Points.hpp"
#include <string>

enum class State {active, inactive};

class Monster: public Card
{
   Points _hp;
   Points _strength;
   State _state;
 public:
   Monster(Points hp, Points strength, std::string name, std::string description, uint manaCost);
   void activateCard();
   State getState() const;
   Points getHp() const;
   void setHp(Points hp);
   Points getStrength() const;
   void setStrength(Points strength);
};
