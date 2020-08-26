#include "MapGeneratorV1.hpp"
#include "DoorField.hpp"
#include "EmptyField.hpp"
#include "Random.hpp"
#include "Room.hpp"
#include "WallField.hpp"
#include <list>
#include <stdexcept>

#define RoomList std::list<std::shared_ptr<Room>>

namespace
{
RoomList generate_rooms(unsigned width, unsigned height)
{
    auto root = std::make_shared<Room>(width, height);
    std::list<std::shared_ptr<Room>> resultRooms;
    std::list<std::shared_ptr<Room>> tempRooms;
    tempRooms.push_back(root);

    for (auto room : tempRooms)
    {
        if (room->split())
        {
            tempRooms.push_back(room->getLeftChild());
            tempRooms.push_back(room->getRightChild());
        }
        else
        {
            resultRooms.push_back(room);
        }
    }
    return resultRooms;
}

FieldList roomsToFieldList(const RoomList& rooms, unsigned width, unsigned height)
{
    FieldList fieldList;

    for (unsigned x = 0; x < width; x++)
    {
        std::vector<std::unique_ptr<Field>> column;
        for (unsigned y = 0; y < height; y++)
        {
            column.emplace_back(std::make_unique<WallField>());
        }

        fieldList.emplace_back(std::move(column));
    }

    for (auto room : rooms)
    {
        auto borders = room->getRoomBorders();
        for (int x = borders.leftBorder + 1; x < borders.rightBorder; ++x)
        {
            for (int y = borders.bottomBorder + 1; y < borders.upperBorder; ++y)
            {
                fieldList.at(x).at(y) = std::make_unique<EmptyField>();
            }
        }
    }
    return fieldList;
}

bool isDoorPossible(const Position& position, const FieldList& board)
{
    if (board.at(position._x).at(position._y)->getType() != FieldType::Wall)
    {
        return false;
    }
    int neighbourWalls = 0;
    try
    {
        if (board.at(position._x + 1).at(position._y)->getType() == FieldType::Wall)
        {
            ++neighbourWalls;
        }
        if (board.at(position._x).at(position._y + 1)->getType() == FieldType::Wall)
        {
            ++neighbourWalls;
        }
        if (board.at(position._x - 1).at(position._y)->getType() == FieldType::Wall)
        {
            ++neighbourWalls;
        }
        if (board.at(position._x).at(position._y - 1)->getType() == FieldType::Wall)
        {
            ++neighbourWalls;
        }
    }
    catch (std::out_of_range&)
    {
    }
    if (neighbourWalls > 2)
    {
        return false;
    }
    return true;
}

bool isFieldOnBoard(const Position& position, const FieldList& board)
{
    if (position._x < 0 or position._y < 0)
    {
        return false;
    }
    if (position._x > (int)board.size() or position._y > (int)board.at(0).size())
    {
        return false;
    }
    return true;
}

FieldList& buildDoors(const RoomList& rooms, FieldList& board)
{
    for (auto room : rooms)
    {
        auto borders = room->getRoomBorders();

        while (true)
        {
            auto door = Position(random(borders.leftBorder + 1, borders.rightBorder - 1), borders.bottomBorder);
            if (not isFieldOnBoard(door, board))
            {
                break;
            }
            if (isDoorPossible(door, board))
            {
                board.at(door._x).at(door._y) = std::make_unique<DoorField>();
                break;
            }
        }
        while (true)
        {
            auto door = Position(borders.leftBorder, random(borders.bottomBorder + 1, borders.upperBorder - 1));
            if (not isFieldOnBoard(door, board))
            {
                break;
            }
            if (isDoorPossible(door, board))
            {
                board.at(door._x).at(door._y) = std::make_unique<DoorField>();
                break;
            }
        }
    }
    return board;
}
} // namespace

namespace MapGeneratorV1
{
SquareMap generate(unsigned width, unsigned height)
{
    auto rooms = generate_rooms(width, height);
    auto fieldList = roomsToFieldList(rooms, width, height);
    /* fieldList = std::move(buildDoors(rooms, fieldList)); */ // todo: examine why not working
    /* return SquareMap(std::move(fieldList)); */
    return SquareMap(std::move(buildDoors(rooms, fieldList)));
}
} // namespace MapGeneratorV1
