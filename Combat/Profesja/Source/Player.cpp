#include "Player.hpp"

Player::Player(Points HP, Points MP, int Handdeck_size, int _xCoordinate, int _yCoordinate)
    :  _HP(HP),
       _MP(MP),
       _playersHanddeck(Handdeck_size),
       _position(_xCoordinate, _yCoordinate)
{}

const Position& Player::getCurrentPosition()
{
    return _position;
}

void Player::setNewPosition(const Position& targetPosition)
{
    _position = targetPosition;
}
