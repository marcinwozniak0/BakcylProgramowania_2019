#include "MageRaceUltimate.hpp"
#include <iostream>

Ultimate_Mage_Race::Ultimate_Mage_Race(int h, int d) : heal(h), dmg(d){
}

std::string Ultimate_Mage_Race::useUlt()
{
  return "useMageUlt";
}
