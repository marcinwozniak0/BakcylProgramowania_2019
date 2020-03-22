#pragma once
#include "Map.hpp"
#include "Position.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    SquareMap(const int mapSize);

    char printField(const Field& field);
    void updateVisilibity(const Position& playerPosition);

private:
    FieldList _fieldList;

    bool isFieldAccessible(const Position& position);
    bool isField(const Position& position);
    const std::unique_ptr<Field>& getField(const Position& position);

    void makeRoomVisible(const Position& startPosition);
    void makeRowVisible(const Position& startPosition);
};
