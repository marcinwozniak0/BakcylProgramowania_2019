#pragma once
#include "Points.hpp"
#include "Position.hpp"
#include <string>
#include <vector>

class Player
{
public:
  Points _hp;
  Points _mp;
  std::vector<std::string> handdeck;
  Player(Points hp, Points mp, int _xCoordinate = 0, int _yCoordinate = 0);
  const Position& getCurrentPosition();
  void setNewPosition(const Position& targetPosition);

  private:
  Position _position;
};
