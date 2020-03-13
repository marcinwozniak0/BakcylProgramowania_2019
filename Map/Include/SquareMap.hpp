#pragma once
#include "Map.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    SquareMap(const int mapSize);

private:
    FieldList _fieldList;
    bool isMovePossible(std::pair<int, int>, char);
    bool isMoveUpPossible(std::pair<int, int>);
    bool isMoveDownPossible(std::pair<int, int>);
    bool isMoveRightPossible(std::pair<int, int>);
    bool isMoveLeftPossible(std::pair<int, int>);
};
