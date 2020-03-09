#pragma once
#include "Map.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    SquareMap(const int mapSize);

private:
    FieldList _fieldList;
    bool isMoveUpPossible(int, int);
    bool isMoveDownPossible(int, int);
    bool isMoveRightPossible(int, int);
    bool isMoveLeftPossible(int, int);
};
