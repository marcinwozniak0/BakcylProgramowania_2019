#pragma once
#include "Map.hpp"
#include "Position.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    SquareMap(const int mapSize);

    char printField(const Field& field);
    void updateVisilibity(const Position& playerPos);

private:
    FieldList _fieldList;

    bool isFieldAccessible(const Position& position);
    const std::unique_ptr<Field>& getField(const Position& position);

    void makeRoomVisible(const Position& startPos);
    void makeRowVisible(const Position& startPos);
};
