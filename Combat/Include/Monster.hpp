#pragma once
#include "Card.hpp"
#include "Points.hpp"


class Monster : public Card
{
   public:
        Points _hp;
        Points _strength;
        enum class State {active, inactive};
        State _state;

        Monster(Points hp, Points strength, uint manaCost);
        void activateCard();
        void dealDamage(Points& hp1, uint amount);
};
