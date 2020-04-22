#pragma once

#include "Map.hpp"
#include "Position.hpp"

class SquareMap : public Map
{
public:
    const FieldList& getFields();
    SquareMap(const int mapSize);
    SquareMap(FieldList&& fieldList);

    char printField(const std::unique_ptr<Field>& field);
    void updateVisilibity(const Position& playerPosition);
    std::string getMapToPrint(const Position& playerPosition);
    bool isMovePossible(const Position&, const Direction);

private:
    bool isMoveUpPossible(const Position&);
    bool isMoveDownPossible(const Position&);
    bool isMoveRightPossible(const Position&);
    bool isMoveLeftPossible(const Position&);
    bool isFieldAccessible(const Position& position);
    bool isFieldBelongToMap(const Position& position);
    bool isFieldBarrier(const Position& position);
    void makeNonBarrierFieldsInvisible();
    void makeRoomVisible(const Position& startPosition);
    void makeRowVisible(const Position& startPosition);
    void makeUpperRowsVisible(Position position);
    void makeLowerRowsVisible(Position position);
    void makeLeftHandFieldsVisible(Position position);
    void makeRightHandFieldsVisible(Position position);
    std::string getMapColumnNumbersToPrint(const unsigned int mapSize);
    std::string getMapHorizontalFrameToPrint(const unsigned int mapSize);
    std::string getFieldsToPrint(const unsigned int mapSize);
    void markPlayerPosition(std::string& str, const Position& playerPosition, const unsigned int mapSize);
    const std::unique_ptr<Field>& getField(const Position& position);
    
    FieldList _fieldList;
};
