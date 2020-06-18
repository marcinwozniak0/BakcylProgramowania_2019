#pragma once
#include "Ultimate.hpp"
#include <iostream>

class Ultimate_Warrior_Race : public Ultimate
{
  private:
    int heal;
    int dmg;
  public:
    Ultimate_Warrior_Race(int = 3,int = 6);
    virtual std::string useUlt();
};
