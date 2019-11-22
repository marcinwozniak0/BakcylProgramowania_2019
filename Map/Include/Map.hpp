#pragma once
#include "Room.hpp"
#include <vector>

class Map
{
public:
    std::vector<Room> getRooms();
    Map();
    Map(int mapSize);
private:
    std::vector<Room> rooms;
};
