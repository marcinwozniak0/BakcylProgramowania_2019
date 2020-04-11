#include "Monster.hpp"
#include "Points.hpp"
#include <iostream>

Monster::Monster(Points hp, Points strength, std::string name, std::string description, uint manaCost, uint cardID)
:
Card(name, description, manaCost, cardID),
_hp(hp),
_strength(strength),
_state(State::inactive)
{}

void Monster::activateCard()
{
   _state = State::active;
}

void Monster::dealDamage(Points& hp1, uint amount)
{
    hp1.remove(amount);
}
