#pragma once
#include "Map.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    SquareMap(const int mapSize);
    bool isMovePossible(const char, int&, int&);
private:
    FieldList _fieldList;
};
