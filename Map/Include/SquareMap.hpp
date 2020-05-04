#pragma once

#include "Map.hpp"
#include "Position.hpp"
#include "RoomBorders.hpp"

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
    bool isFieldBelongToRoom(const Position& position, const RoomBorders& roomBorders);
    int CalculateLeftBorder(Position position);
    int CalculateRightBorder(Position position);
    int CalculateUpperBorder(Position position);
    int CalculateBottomBorder(Position position);
    void makeNonBarrierFieldsInvisible();
    void makeRoomVisible(const Position& startPosition);
    void makeRowVisible(const Position& startPosition, const RoomBorders& roomBorders);
    void makeUpperRowsVisible(Position position, const RoomBorders& roomBorders);
    void makeLowerRowsVisible(Position position, const RoomBorders& roomBorders);
    void makeLeftHandFieldsVisible(Position position, const RoomBorders& roomBorders);
    void makeRightHandFieldsVisible(Position position, const RoomBorders& roomBorders);
    std::string getMapColumnNumbersToPrint(const unsigned int mapSize);
    std::string getMapHorizontalFrameToPrint(const unsigned int mapSize);
    std::string getFieldsToPrint(const unsigned int mapSize);
    void markPlayerPosition(std::string& str, const Position& playerPosition, const unsigned int mapSize);
    const std::unique_ptr<Field>& getField(const Position& position);
    
    FieldList _fieldList;
};
