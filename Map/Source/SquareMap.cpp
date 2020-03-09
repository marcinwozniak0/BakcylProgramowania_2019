#include "SquareMap.hpp"
#include "EmptyField.hpp"
#include "Field.hpp"
#include <memory>
#include <vector>

const FieldList& SquareMap::getFields()
{
    return _fieldList;
}

SquareMap::SquareMap(const int mapSize)
{
    for (int x = 0; x < mapSize; x++)
    {
        std::vector<std::unique_ptr<Field>> column;
        for (int y = 0; y < mapSize; y++)
        {
            column.emplace_back(std::make_unique<EmptyField>());
        }

        _fieldList.emplace_back(std::move(column));
    }
}

bool SquareMap::isMoveUpPossible(const int x, const int y)
{
    if(y + 1u < _fieldList.size())
    {
        if(_fieldList.at(x).at(y + 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveDownPossible(const int x, const int y)
{
    if(y - 1 >= 0)
    {
        if(_fieldList.at(x).at(y - 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveRightPossible(const int x, const int y)
{
    if(x + 1u < _fieldList.size())
    {
        if(_fieldList.at(x + 1).at(y) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveLeftPossible(const int x, const int y)
{
    if(x - 1 >= 0)
    {
        if(_fieldList.at(x - 1).at(y) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}