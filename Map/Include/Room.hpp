#pragma once
#include "Position.hpp"
#include "RoomBorders.hpp"
#include "SplitDirection.hpp"
#include <memory>

class Room
{
public:
    Room(RoomBorders borders);
    Room(unsigned width, unsigned height);
    bool split();
    const std::shared_ptr<Room>& getLeftChild();
    const std::shared_ptr<Room>& getRightChild();
    const RoomBorders& getRoomBorders();

private:
    std::shared_ptr<Room> _leftChild;
    std::shared_ptr<Room> _rightChild;
    RoomBorders _borders;
    int calculateSplitPosition(const SplitDirection& splitDirection);
    SplitDirection calculateSplitDirection();
};
