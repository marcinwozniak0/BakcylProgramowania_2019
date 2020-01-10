#pragma once
#include "Ultimate.hpp"
#include <iostream>

class Ultimate_Mage_Race : public Ultimate
{
  private:
    int heal;
    int dmg;
  public:
    Ultimate_Mage_Race(int = 8,int = 2);
    virtual std::string useUlt();
};
