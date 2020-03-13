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

void SquareMap::updateVisilibity(const Position& playerPosition)
{
    if (getField(playerPosition)->getType() == FieldType::Door)
    {
        makeRoomVisible(Position(playerPosition._x + 1, playerPosition._y));
        makeRoomVisible(Position(playerPosition._x - 1, playerPosition._y));
        makeRoomVisible(Position(playerPosition._x, playerPosition._y + 1));
        makeRoomVisible(Position(playerPosition._x, playerPosition._y - 1));
    }
    else
    {
        makeRoomVisible(playerPosition);
    }
}

void SquareMap::makeRoomVisible(const Position& startPosition)
{
    if (not isFieldAccessible(startPosition))
    {
        return;
    }

    Position tempPosition = startPosition;

    while (isFieldAccessible(tempPosition) and getField(tempPosition)->getType() != FieldType::Door)
    {
        makeRowVisible(tempPosition);
        ++tempPosition._y;
    }

    tempPosition = startPosition;
    --tempPosition._y;

    while (isFieldAccessible(tempPosition) and getField(tempPosition)->getType() != FieldType::Door)
    {
        makeRowVisible(tempPosition);
        --tempPosition._y;
    }
}

void SquareMap::makeRowVisible(const Position& startPosition)
{
    if (not isFieldAccessible(startPosition) or getField(startPosition)->getType() == FieldType::Door)
    {
        return;
    }

    Position tempPosition = startPosition;

    while (isFieldAccessible(tempPosition) and getField(tempPosition)->getType() != FieldType::Door)
    {
        getField(tempPosition)->makeVisible();
        ++tempPosition._x;
    }

    tempPosition = startPosition;
    --tempPosition._x;

    while (isFieldAccessible(tempPosition) and getField(tempPosition)->getType() != FieldType::Door)
    {
        getField(tempPosition)->makeVisible();
        --tempPosition._x;
    }
}
