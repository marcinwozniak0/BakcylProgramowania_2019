#pragma once
struct Position
{
    int _x;
    int _y;
    Position(int x, int y);
};

const bool operator==(const Position& lhs, const Position& rhs);
