#include "Player.hpp"

Player::Player(Points hp, Points mp, int _xCoordinate, int _yCoordinate, Profession ProfType)
    : _hp(hp), _mp(mp), _ProfType(ProfType), _position(_xCoordinate, _yCoordinate)
{
  handdeck = {"karta1", "karta2", "karta3"};

}

const Position& Player::getCurrentPosition()
{
    return _position;
}

void Player::setNewPosition(const Position& targetPosition)
{
    _position = targetPosition;
}
