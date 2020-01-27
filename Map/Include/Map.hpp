#pragma once
#include "Field.hpp"
#include <memory>
#include <vector>

class Map
{
public:
    std::vector<std::vector<std::unique_ptr<Field>>> const &getFields();
    Map();
    Map(int mapSize);

private:
    std::vector<std::vector<std::unique_ptr<Field>>> _fields;
};
