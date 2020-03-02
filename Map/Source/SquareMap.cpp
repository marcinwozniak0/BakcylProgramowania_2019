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
      default:
        return '?';
    }
  }
  else
  {
    return ' ';
  }
}

SquareMap::SquareMap(const int &mapSize)
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