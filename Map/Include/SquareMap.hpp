#pragma once
#include "Map.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    SquareMap(const int mapSize);

private:
    FieldList _fieldList;
};
