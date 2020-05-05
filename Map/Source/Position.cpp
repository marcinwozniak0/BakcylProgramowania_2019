#include "Position.hpp"

Position::Position(int x, int y) : _x(x), _y(y)
{
}

const bool operator==(const Position& lhs, const Position& rhs)
{
    return (lhs._x == rhs._x and lhs._y == rhs._y);
}
