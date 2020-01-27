#include "Map.hpp"
#include "EmptyField.hpp"
#include "Field.hpp"
#include <memory>
#include <vector>

std::vector<std::vector<std::unique_ptr<Field>>> const &Map::getFields()
{
    return _fields;
}

Map::Map(int mapSize)
{
    for (int x = 0; x < mapSize; x++)
    {
        std::vector<std::unique_ptr<Field>> column;
        for (int y = 0; y < mapSize; y++)
        {
            column.push_back(std::move(std::make_unique<EmptyField>()));
        }

        _fields.push_back(std::move(column));
    }
}
