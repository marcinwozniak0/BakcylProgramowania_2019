#include "SquareMap.hpp"
#include "EmptyField.hpp"
#include "TreasureField.hpp"
#include "FightField.hpp"
#include "Field.hpp"
#include <memory>
#include <stdexcept>
#include <vector>
#include <sstream>

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

bool SquareMap::isMovePossible(const Position& coordinates, const char pressedKey)
{
    switch(pressedKey)
    {
        case 'w':
        {
            if(isMoveUpPossible(coordinates))
            {
                return true;
            };
            break;
        }
        case 'a':
        {
            if(isMoveLeftPossible(coordinates))
            {
                return true;
            };
            break;
        }
        case 's':
        {
            if(isMoveDownPossible(coordinates))
            {
                return true;
            }
            break;
        }
        case 'd':
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
    if(coordinates._y + 1u < _fieldList.size())
    {
        if(_fieldList.at(coordinates._x).at(coordinates._y + 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveDownPossible(const Position& coordinates)
{
    if(coordinates._y - 1 >= 0)
    {
        if(_fieldList.at(coordinates._x).at(coordinates._y - 1) -> getType() != FieldType::Wall)
        {
            return true;
        }
    }
    return false;
}

bool SquareMap::isMoveRightPossible(const Position& coordinates)
{
    if(coordinates._x + 1u < _fieldList.size())
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
    if(coordinates._x - 1 >= 0)
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

    makeRowVisible(startPosition);

    makeUpperRowsVisible(startPosition);
    makeLowerRowsVisible(startPosition);
}

void SquareMap::makeUpperRowsVisible(Position position)
{
    while (not isFieldBarrier(position))
    {
        ++position._y;
        if (not isFieldBelongToMap(position))
        {
            return;
        }
        makeRowVisible(position);
    }
}
void SquareMap::makeLowerRowsVisible(Position position)
{
    while (not isFieldBarrier(position))
    {
        --position._y;
        if (not isFieldBelongToMap(position))
        {
            return;
        }
        makeRowVisible(position);
    }
}

void SquareMap::makeRowVisible(const Position& startPosition)
{
    if (not isFieldBelongToMap(startPosition))
    {
        return;
    }

    getField(startPosition)->makeVisible();
    if (isFieldBarrier(startPosition))
    {
        return;
    }

    makeLeftHandFieldsVisible(startPosition);
    makeRightHandFieldsVisible(startPosition);
}

void SquareMap::makeLeftHandFieldsVisible(Position position)
{
    while (not isFieldBarrier(position))
    {
        ++position._x;
        if (not isFieldBelongToMap(position))
        {
            return;
        }
        getField(position)->makeVisible();
    }
}

void SquareMap::makeRightHandFieldsVisible(Position position)
{
    while (not isFieldBarrier(position))
    {
        --position._x;
        if (not isFieldBelongToMap(position))
        {
            return;
        }
        getField(position)->makeVisible();
    }
}
