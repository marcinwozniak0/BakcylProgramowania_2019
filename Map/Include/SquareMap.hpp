#pragma once
#include "Map.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    char printField(const Field& field);
    SquareMap(const int mapSize);

private:
    FieldList _fieldList;
};
