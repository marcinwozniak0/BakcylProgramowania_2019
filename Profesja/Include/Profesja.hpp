#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <optional>

class Player
{
public:
  uint currentHp = 20;
  std::vector<std::string> handdeck = {"karta1", "karta2", "karta3"};
};

class Profession
{
 public:
  virtual void useUlt(std::optional<Player>& p1, std::optional<Player>& p2) = 0;
};

class Paladin : public Profession
{
 public:
  uint power;
  void useUlt(std::optional<Player>& p1, std::optional<Player>& p2) override;
};

class Mage : public Profession
{
 public:
  uint power;
  void useUlt(std::optional<Player>& p1, std::optional<Player>& p2) override;
};

class Rogue : public Profession
{
 public:
  uint rng = 0;
  void useUlt(std::optional<Player>& p1, std::optional<Player>& p2) override;
};
