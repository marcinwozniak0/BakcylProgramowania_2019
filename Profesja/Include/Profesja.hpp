#pragma once
#include <iostream>
#include <vector>
#include <string>

class Player
{
  uint currentHp = 20;
  std::vector<std::string> handdeck = {"karta1", "karta2", "karta3"};
  class Profession
  {
   public:
    virtual void useUlt(this, Player& p2) = 0;
  };

  class Paladin : public Profession
  {
   public:
    void useUlt(Player& p1, Player& p2) override;
  };

  class Mage : public Profession
  {
   public:
    void useUlt(this, Player& p2) override;
  };

  class Rogue : public Profession
  {
   public:
    void useUlt(this, Player& p2) override;
  };

};
