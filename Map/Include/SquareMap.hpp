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
    std::string getMapToPrint(const Position& playerPosition);

private:
    bool isMovePossible(const Position&, const char);
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
    void printColumnNumbers(std::ostream& str, const int mapSize);
    void printFrameHorizontal(std::ostream& str, const int mapSize);
    void printFieldRows(std::ostream& str, const int mapSize);
    void markPlayerPosition(std::string& str, const Position& playerPosition)
    const std::unique_ptr<Field>& getField(const Position& position);
    
    FieldList _fieldList;
};
