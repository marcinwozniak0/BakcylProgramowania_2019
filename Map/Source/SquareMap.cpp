#include "SquareMap.hpp"
#include "EmptyField.hpp"
#include "TreasureField.hpp"
#include "FightField.hpp"
#include "Field.hpp"
#include <memory>
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

bool SquareMap::isMovePossible(std::pair<int, int> coordinates, const char pressedKey)
{
    switch(pressedKey)
    {
        case 'w':
        {
            if(isMoveUpPossible(coordinates))
            {
                return true;
            };
            break;
        }
        case 'a':
        {
            if(isMoveLeftPossible(coordinates))
            {
                return true;
            };
            break;
        }
        case 's':
        {
            if(isMoveDownPossible(coordinates))
            {
                return true;
            }
            break;
        }
        case 'd':
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

bool SquareMap::isMoveUpPossible(std::pair<int, int> coordinates)
{
    if(std::get<1>(coordinates) + 1u < _fieldList.size())
    {
        if(_fieldList.at(std::get<0>(coordinates)).at(std::get<1>(coordinates) + 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveDownPossible(std::pair<int, int> coordinates)
{
    if(std::get<1>(coordinates) - 1 >= 0)
    {
        if(_fieldList.at(std::get<0>(coordinates)).at(std::get<1>(coordinates) - 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveRightPossible(std::pair<int, int> coordinates)
{
    if(std::get<0>(coordinates) + 1u < _fieldList.size())
    {
        if(_fieldList.at(std::get<0>(coordinates) + 1).at(std::get<1>(coordinates)) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveLeftPossible(std::pair<int, int> coordinates)
{
    if(std::get<0>(coordinates) - 1 >= 0)
    {
        if(_fieldList.at(std::get<0>(coordinates) - 1).at(std::get<1>(coordinates)) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}