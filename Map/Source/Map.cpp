#include <EmptyField.hpp>
#include "Map.hpp"

bool Map::isMovePossible(const Position& coordinates, const Direction& direction)
{
    switch(direction)
    {
        case Direction::Up:
        {
            if(isMoveUpPossible(coordinates))
            {
                return true;
            };
            break;
        }
        case Direction::Left:
        {
            if(isMoveLeftPossible(coordinates))
            {
                return true;
            };
            break;
        }
        case Direction::Down:
        {
            if(isMoveDownPossible(coordinates))
            {
                return true;
            }
            break;
        }
        case Direction::Right:
        {
            if(isMoveRightPossible(coordinates))
            {
                return true;
            }
            break;
        }
    }
    return false;
}

bool Map::isMoveUpPossible(const Position& coordinates)
{
    if(coordinates._y > 0)
    {
        if(getFields().at(coordinates._x).at(coordinates._y - 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool Map::isMoveDownPossible(const Position& coordinates)
{
    if(coordinates._y + 1 < getFields().size())
    {
        if(getFields().at(coordinates._x).at(coordinates._y + 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool Map::isMoveRightPossible(const Position& coordinates)
{
    if(coordinates._x + 1 < getFields().size())
    {
        if(getFields().at(coordinates._x + 1).at(coordinates._y) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool Map::isMoveLeftPossible(const Position& coordinates)
{
    if(coordinates._x > 0)
    {
        if(getFields().at(coordinates._x - 1).at(coordinates._y) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

void Map::makeFieldEmpty(const Position& position)
{
    if(position._x < 0 || position._y < 0 || position._x >= getFields().size() || position._y >= getFields().size())
    {
        throw std::out_of_range("Out of range");
    }

    const_cast<FieldList&>(getFields()).at(position._x).at(position._y) = std::make_unique<EmptyField>();
}
