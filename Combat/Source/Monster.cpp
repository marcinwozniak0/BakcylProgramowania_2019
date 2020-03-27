#include "Monster.hpp"
#include "Points.hpp"
#include <iostream>

Monster::Monster(Points hp, Points strength, uint manaCost)
:
_hp(hp),
_strength(strength),
_state(State::inactive)
{
   _manaCost = manaCost;
}

void Monster::activateCard()
{
   _state = State::active;
}

void Monster::dealDamage(Points& hp1, uint amount)
{
    hp1.remove(amount);
}
