#include "WarriorRaceUltimate.hpp"
#include <iostream>

Ultimate_Warrior_Race::Ultimate_Warrior_Race(int h, int d): heal(h), dmg(d){
}

std::string Ultimate_Warrior_Race::useUlt()
{
  return "useWarriorUlt";
}
