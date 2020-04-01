#pragma once
#include "Map.hpp"
#include "Position.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    SquareMap(const int mapSize);
    SquareMap(FieldList&& fieldList);

    char printField(const Field& field);
    void updateVisilibity(const Position& playerPosition);

private:
    FieldList _fieldList;
    bool isMovePossible(const Position&, const char);
    bool isMoveUpPossible(const Position&);
    bool isMoveDownPossible(const Position&);
    bool isMoveRightPossible(const Position&);
    bool isMoveLeftPossible(const Position&);
    bool isFieldAccessible(const Position& position);
    bool isField(const Position& position);
    void makeNonBarrierFieldsInvisible();
    void makeRoomVisible(const Position& startPosition);
    void makeRowVisible(const Position& startPosition);
    const std::unique_ptr<Field>& getField(const Position& position);
};
