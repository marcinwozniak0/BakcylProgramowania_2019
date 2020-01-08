#include "Ultimate.hpp"
#include <iostream>

Ultimate_Mage_Race::Ultimate_Mage_Race(int h, int d) : heal(h), dmg(d){
}

Ultimate_Warrior_Race::Ultimate_Warrior_Race(int h, int d): heal(h), dmg(d){
}

std::string Ultimate_Mage_Race::useUlt()
{
  return "useMageUlt";
}

std::string Ultimate_Warrior_Race::useUlt()
{
  return "useWarriorUlt";
}
