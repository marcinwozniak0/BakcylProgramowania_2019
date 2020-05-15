#pragma once
struct Position
{
    unsigned int _x;
    unsigned int _y;
    Position(int x, int y);
};

const bool operator==(const Position& lhs, const Position& rhs);
