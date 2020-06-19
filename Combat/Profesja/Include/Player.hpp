#pragma once
#include "Points.hpp"
#include "Position.hpp"
#include <string>
#include <vector>

class Player
{
  enum Profession
  {
    Default = 0, Mage = 1, Paladin = 2, Rogue = 3,
  };
public:
  Points _hp;
  Points _mp;
  const Profession _ProfType;
  std::vector<std::string> handdeck;
  Player(Points hp, Points mp, int _xCoordinate = 0, int _yCoordinate = 0, Profession ProfType = Default);
  const Position& getCurrentPosition();
  void setNewPosition(const Position& targetPosition);
  private:
  Position _position;
};
