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

void SquareMap::move(const char &pressedKey, int &x, int &y)
{
    switch(pressedKey)
    {
        case 'W':
        {
            if(y + 1 < _fieldList.size() && _fieldList.at(x).at(y + 1) -> getType() != FieldType::Wall)
            {
                //zmienić typ pola, na którym stoi gracz
                //zmienić typ pola, na które wchodzi gracz
                ++y;
            }
            break;
        }
        case 'A':
        {
            if(x - 1 >= 0 && _fieldList.at(x - 1).at(y) -> getType() != FieldType::Wall)
            {
                //zmienić typ pola, na którym stoi gracz
                //zmienić typ pola, na które wchodzi gracz
                --x;
            }
            break;
        }
        case 'S':
        {
            if(y - 1 >= 0 && _fieldList.at(x).at(y - 1) -> getType() != FieldType::Wall)
            {
                //zmienić typ pola, na którym stoi gracz
                //zmienić typ pola, na które wchodzi gracz
                --y;
            }
            break;
        }
        case 'D':
        {
            if(x + 1 < _fieldList.size() && _fieldList.at(x + 1).at(y) -> getType() != FieldType::Wall)
            {
                //zmienić typ pola, na którym stoi gracz
                //zmienić typ pola, na które wchodzi gracz
                ++x;
            }
            break;
        }
        default:
        {
            break;
        }
    }
}