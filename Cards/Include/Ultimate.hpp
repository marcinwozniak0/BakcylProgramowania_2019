#pragma once
#include <iostream>

class Ultimate
{
  public:
         virtual std::string useUlt() = 0;
};

class Ultimate_Mage_Race : public Ultimate
{
  public:
          int heal;
          int dmg;
          Ultimate_Mage_Race(int = 8,int = 2);
          virtual std::string useUlt();
};

class Ultimate_Warrior_Race : public Ultimate
{
  public:
          int heal;
          int dmg;
          Ultimate_Warrior_Race(int = 3,int = 6);
          virtual std::string useUlt();
};
