#include "SquareMap.hpp"
#include "EmptyField.hpp"
#include "TreasureField.hpp"
#include "FightField.hpp"
#include "Field.hpp"
#include <memory>
#include <stdexcept>
#include <vector>

const FieldList& SquareMap::getFields()
{
    return _fieldList;
}

char SquareMap::printField(const Field& field)
{
  if(field.isVisible())
  {
    FieldType type = field.getType();
    switch (type) {
      case FieldType::Empty:
        return '.';
      case FieldType::Wall:
        return '#';
      case FieldType::Fight:
        return 'F';
      case FieldType::Treasure:
        return 'T';
      case FieldType::Door:
        return 'D';
      default:
        return '?';
    }
  }
  else
  {
    return ' ';
  }
}

SquareMap::SquareMap(const int mapSize)
{
    for(int x = 0; x < mapSize; x++)
    {
        std::vector<std::unique_ptr<Field>> column;
        for(int y = 0; y < mapSize; y++)
        {
            column.emplace_back(std::make_unique<EmptyField>());
        }

        _fieldList.emplace_back(std::move(column));
    }

    const int numberOfTreasureFields = mapSize / 2;
    const int numberOfFightFields = mapSize / 2;

    for(int i = 1; i <= numberOfTreasureFields; i++)
    {
        _fieldList.at(0).at(i) = std::make_unique<TreasureField>();
    }

    for(int i = 1; i <= numberOfFightFields; i++)
    {
        _fieldList.at(i).at(0) = std::make_unique<FightField>();
    }
}

bool SquareMap::isFieldAccessible(const Position& position)
{
    try
    {
        if (getField(position)->getType() == FieldType::Wall)
        {
            return false;
        }
    }
    catch (std::out_of_range&)
    {
        return false;
    }
    return true;
}

const std::unique_ptr<Field>& SquareMap::getField(const Position& position)
{
    return _fieldList.at(position._x).at(position._y);
}

void SquareMap::updateVisilibity(const Position& playerPos)
{
    if (getField(playerPos)->getType() == FieldType::Door)
    {
        makeRoomVisible(Position(playerPos._x + 1, playerPos._y));
        makeRoomVisible(Position(playerPos._x - 1, playerPos._y));
        makeRoomVisible(Position(playerPos._x, playerPos._y + 1));
        makeRoomVisible(Position(playerPos._x, playerPos._y - 1));
    }
    else
    {
        makeRoomVisible(playerPos);
    }
}

void SquareMap::makeRoomVisible(const Position& startPos)
{
    if (!isFieldAccessible(startPos))
    {
        return;
    }

    Position tempPos = startPos;

    while (isFieldAccessible(tempPos) && getField(tempPos)->getType() != FieldType::Door)
    {
        makeRowVisible(tempPos);
        ++tempPos._y;
    }

    tempPos = startPos;
    --tempPos._y;

    while (isFieldAccessible(tempPos) && getField(tempPos)->getType() != FieldType::Door)
    {
        makeRowVisible(tempPos);
        --tempPos._y;
    }
}

void SquareMap::makeRowVisible(const Position& startPos)
{
    if (!isFieldAccessible(startPos) || getField(startPos)->getType() == FieldType::Door)
    {
        return;
    }

    Position tempPos = startPos;

    while (isFieldAccessible(tempPos) && getField(tempPos)->getType() != FieldType::Door)
    {
        getField(tempPos)->makeVisible();
        ++tempPos._x;
    }

    tempPos = startPos;
    --tempPos._x;

    while (isFieldAccessible(tempPos) && getField(tempPos)->getType() != FieldType::Door)
    {
        getField(tempPos)->makeVisible();
        --tempPos._x;
    }
}
