#pragma once
#include "Points.hpp"
#include "Position.hpp"
#include "LimitedDeck.hpp"
#include <string>
#include <cstdint>
#include <vector>

using HP = Points;
using MP = Points;

class Player
{
  enum Profession
  {
    Default = 0, Mage = 1, Paladin = 2, Rogue = 3,
  };
public:
  HP _HP;
  MP _MP;
  HandDeck _playersHanddeck;
  Deck _playersPulldeck;
  Player(Points HP, Points MP, int Handdeck_size, int _xCoordinate = 0, int _yCoordinate = 0);
  const Position& getCurrentPosition();
  void setNewPosition(const Position& targetPosition);
  private:
  Position _position;
};
