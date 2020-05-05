#include "SquareMap.hpp"
#include "EmptyField.hpp"
#include "Field.hpp"
#include "FightField.hpp"
#include "RoomBorders.hpp"
#include "TreasureField.hpp"
#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>

const FieldList& SquareMap::getFields()
{
    return _fieldList;
}

char SquareMap::printField(const std::unique_ptr<Field>& field)
{
    if(field->isVisible())
    {
        FieldType type = field->getType();
        switch (type) {
            case FieldType::Empty:
                return '.';
            case FieldType::Wall:
                return '#';
            case FieldType::Fight:
                return 'F';
            case FieldType::Treasure:
                return 'T';
            case FieldType::Door:
                return 'D';
            default:
                return '?';
        }
    }
    else
    {
        return ' ';
    }
}

std::string SquareMap::getMapToPrint(const Position& playerPosition)
{
    std::stringstream output;
    
    const unsigned int mapSize = _fieldList.size();
    
    output << getMapColumnNumbersToPrint(mapSize);
    
    output << getMapHorizontalFrameToPrint(mapSize);
    
    output << getFieldsToPrint(mapSize);
    
    output << getMapHorizontalFrameToPrint(mapSize);
    
    std::string outputString = output.str();
    
    markPlayerPosition(outputString, playerPosition, mapSize);
    
    return outputString;
}

std::string SquareMap::getMapColumnNumbersToPrint(const unsigned int mapSize)
{
    std::stringstream str;
    
    str << "   ";
    for(unsigned int ite = 0; ite < mapSize; ++ite)
    {
        str << ' ' << (ite + 1) % 10;
    }
    str << '\n';
    
    return str.str();
}

std::string SquareMap::getMapHorizontalFrameToPrint(const unsigned int mapSize)
{
    std::stringstream str;
    
    const auto mapFrameWidth = mapSize * 2 + 3;
    
    str << "  ";
    for(unsigned int ite = 0; ite < mapFrameWidth; ++ite)
    {
        str << '#';
    }
    str << '\n';
    
    return str.str();
}

std::string SquareMap::getFieldsToPrint(const unsigned int mapSize)
{
    std::stringstream str;
    
    for(unsigned int row = 0; row < mapSize; ++row)
    {
        str << (row + 1) % 10 << " #";
        for(unsigned int column = 0; column < mapSize; ++column)
        {
            if(isFieldBarrier(Position(column,row)) && _fieldList.at(column).at(row)->isVisible())
            {
                if(column == 0)
                {
                    str << '#' << printField(_fieldList.at(column).at(row));
                }
                else if(isFieldBarrier(Position(column - 1,row)) && getField(Position(column - 1,row))->isVisible())
                {
                    str << '#' << printField(_fieldList.at(column).at(row));
                }
                else
                {
                    str << ' ' << printField(_fieldList.at(column).at(row));
                }
            }
            else
            {
                str << ' ' << printField(_fieldList.at(column).at(row));
            }
        }
        if(isFieldBarrier(Position(mapSize - 1,row)) && getField(Position(mapSize - 1,row))->isVisible())
        {
            str << "##\n";
        }
        else
        {
            str << " #\n";
        }
    }
    
    return str.str();
}

void SquareMap::markPlayerPosition(std::string& str, const Position& playerPosition, const unsigned int mapSize)
{
    const auto leadingCharsCount = 14u + mapSize * 4u;
    const auto rowCharCount = 6u + mapSize * 2u;
    constexpr auto fieldWidth = 2u;
    const auto playerPosOnScreen = leadingCharsCount + playerPosition._y * rowCharCount + fieldWidth * playerPosition._x;
    str.at(playerPosOnScreen) = 'P';
}

SquareMap::SquareMap(const int mapSize)
{
    for(int x = 0; x < mapSize; x++)
    {
        std::vector<std::unique_ptr<Field>> column;
        for(int y = 0; y < mapSize; y++)
        {
            column.emplace_back(std::make_unique<EmptyField>());
        }

        _fieldList.emplace_back(std::move(column));
    }

    const int numberOfTreasureFields = mapSize / 2;
    const int numberOfFightFields = mapSize / 2;

    for(int i = 1; i <= numberOfTreasureFields; i++)
    {
        _fieldList.at(0).at(i) = std::make_unique<TreasureField>();
    }

    for(int i = 1; i <= numberOfFightFields; i++)
    {
        _fieldList.at(i).at(0) = std::make_unique<FightField>();
    }
}

bool SquareMap::isMovePossible(const Position& coordinates, const Direction direction)
{
    switch(direction)
    {
        case Direction::Up:
        {
            if(isMoveUpPossible(coordinates))
            {
                return true;
            };
            break;
        }
        case Direction::Left:
        {
            if(isMoveLeftPossible(coordinates))
            {
                return true;
            };
            break;
        }
        case Direction::Down:
        {
            if(isMoveDownPossible(coordinates))
            {
                return true;
            }
            break;
        }
        case Direction::Right:
        {
            if(isMoveRightPossible(coordinates))
            {
                return true;
            }
            break;
        }
    }
    return false;
}

bool SquareMap::isMoveUpPossible(const Position& coordinates)
{
    if(coordinates._y > 0)
    {
        if(_fieldList.at(coordinates._x).at(coordinates._y - 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveDownPossible(const Position& coordinates)
{
    if(coordinates._y + 1 < _fieldList.size())
    {
        if(_fieldList.at(coordinates._x).at(coordinates._y + 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveRightPossible(const Position& coordinates)
{
    if(coordinates._x + 1 < _fieldList.size())
    {
        if(_fieldList.at(coordinates._x + 1).at(coordinates._y) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveLeftPossible(const Position& coordinates)
{
    if(coordinates._x > 0)
    {
        if(_fieldList.at(coordinates._x - 1).at(coordinates._y) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

SquareMap::SquareMap(FieldList&& fieldList) : _fieldList(std::move(fieldList))
{
}

bool SquareMap::isFieldAccessible(const Position& position)
{
    if (not isFieldBelongToMap(position) or getField(position)->getType() == FieldType::Wall)
    {
        return false;
    }
    return true;
}

bool SquareMap::isFieldBelongToMap(const Position& position)
try
{
    if (getField(position))
    {
        return true;
    }
    return false;
}
catch (std::out_of_range&)
{
    return false;
}

bool SquareMap::isFieldBarrier(const Position& position)
{
    if (not isFieldBelongToMap(position))
    {
        return false;
    }
    else if (getField(position)->getType() != FieldType::Wall and getField(position)->getType() != FieldType::Door)
    {
        return false;
    }
    return true;
}

const std::unique_ptr<Field>& SquareMap::getField(const Position& position)
{
    return _fieldList.at(position._x).at(position._y);
}

void SquareMap::updateVisilibity(const Position& playerPosition)
{
    makeNonBarrierFieldsInvisible();
    if (getField(playerPosition)->getType() == FieldType::Door)
    {
        makeRoomVisible(Position(playerPosition._x + 1, playerPosition._y));
        makeRoomVisible(Position(playerPosition._x - 1, playerPosition._y));
        makeRoomVisible(Position(playerPosition._x, playerPosition._y + 1));
        makeRoomVisible(Position(playerPosition._x, playerPosition._y - 1));
    }
    else if(not isFieldAccessible(playerPosition))
    {
        return;
    }
    else
    {
        makeRoomVisible(playerPosition);
    }
}

void SquareMap::makeNonBarrierFieldsInvisible()
{
    for(const auto& column : _fieldList)
    {
        for(const auto& field : column)
        {
            if(field->getType() != FieldType::Wall and field->getType() != FieldType::Door)
            {
                field->makeInvisible();
            }
        }
    }
}

void SquareMap::makeRoomVisible(const Position& startPosition)
{
    if (not isFieldBelongToMap(startPosition))
    {
        return;
    }

    RoomBorders roomBorders;
    roomBorders.leftBorder = calculateLeftBorder(startPosition);
    roomBorders.rightBorder = calculateRightBorder(startPosition);
    roomBorders.upperBorder = calculateUpperBorder(startPosition);
    roomBorders.bottomBorder = calculateBottomBorder(startPosition);

    makeRowVisible(startPosition, roomBorders);

    makeUpperRowsVisible(startPosition, roomBorders);
    makeLowerRowsVisible(startPosition, roomBorders);
}

int SquareMap::calculateLeftBorder(Position position)
{
    while (not isFieldBarrier(position))
    {
        --position._x;
        if (not isFieldBelongToMap(position))
        {
            ++position._x;
            break;
        }
    }
    return position._x;
}

int SquareMap::calculateRightBorder(Position position)
{
    while (not isFieldBarrier(position))
    {
        ++position._x;
        if (not isFieldBelongToMap(position))
        {
            --position._x;
            break;
        }
    }
    return position._x;
}

int SquareMap::calculateUpperBorder(Position position)
{
    while (not isFieldBarrier(position))
    {
        ++position._y;
        if (not isFieldBelongToMap(position))
        {
            --position._y;
            break;
        }
    }
    return position._y;
}

int SquareMap::calculateBottomBorder(Position position)
{
    while (not isFieldBarrier(position))
    {
        --position._y;
        if (not isFieldBelongToMap(position))
        {
            ++position._y;
            break;
        }
    }
    return position._y;
}

bool SquareMap::isFieldBelongToRoom(const Position& position, const RoomBorders& roomBorders)
{
    if (position._x > roomBorders.rightBorder)
    {
        return false;
    }
    if (position._x < roomBorders.leftBorder)
    {
        return false;
    }
    if (position._y > roomBorders.upperBorder)
    {
        return false;
    }
    if (position._y < roomBorders.bottomBorder)
    {
        return false;
    }
    return true;
}

void SquareMap::makeUpperRowsVisible(Position position, const RoomBorders& roomBorders)
{
    while (isFieldBelongToRoom(position, roomBorders))
    {
        makeRowVisible(position, roomBorders);
        ++position._y;
    }
}
void SquareMap::makeLowerRowsVisible(Position position, const RoomBorders& roomBorders)
{
    while (isFieldBelongToRoom(position, roomBorders))
    {
        makeRowVisible(position, roomBorders);
        --position._y;
    }
}

void SquareMap::makeRowVisible(const Position& startPosition, const RoomBorders& roomBorders)
{
    if (not isFieldBelongToRoom(startPosition, roomBorders))
    {
        return;
    }

    getField(startPosition)->makeVisible();

    makeLeftHandFieldsVisible(startPosition, roomBorders);
    makeRightHandFieldsVisible(startPosition, roomBorders);
}

void SquareMap::makeLeftHandFieldsVisible(Position position, const RoomBorders& roomBorders)
{
    while (isFieldBelongToRoom(position, roomBorders))
    {
        getField(position)->makeVisible();
        ++position._x;
    }
}

void SquareMap::makeRightHandFieldsVisible(Position position, const RoomBorders& roomBorders)
{
    while (isFieldBelongToRoom(position, roomBorders))
    {
        getField(position)->makeVisible();
        --position._x;
    }
}
