#include "Room.hpp"
#include "Random.hpp"
#include <iostream>

int MIN_ROOM_SIZE = 4;

Room::Room(RoomBorders borders) : _leftChild(nullptr), _rightChild(nullptr), _borders(borders)
{
}

Room::Room(unsigned width, unsigned height) : _leftChild(nullptr), _rightChild(nullptr)
{
    _borders.leftBorder = -1;
    _borders.bottomBorder = -1;
    _borders.upperBorder = height;
    _borders.rightBorder = width;
}

bool Room::split()
{
    auto splitDirection = calculateSplitDirection();
    auto splitPosition = calculateSplitPosition(splitDirection);
    RoomBorders leftChildBorders;
    RoomBorders rightChildBorders;
    int leftChildSize;
    int rightChildSize;

    if (splitDirection == SplitDirection::Horizontal)
    {
        leftChildBorders.leftBorder = rightChildBorders.leftBorder = _borders.leftBorder;
        leftChildBorders.rightBorder = rightChildBorders.rightBorder = _borders.rightBorder;
        leftChildBorders.upperBorder = rightChildBorders.bottomBorder = splitPosition;
        leftChildBorders.bottomBorder = _borders.bottomBorder;
        rightChildBorders.upperBorder = _borders.upperBorder;

        leftChildSize = splitPosition - _borders.bottomBorder - 1;
        rightChildSize = _borders.upperBorder - splitPosition - 1;
    }
    else
    {
        leftChildBorders.bottomBorder = rightChildBorders.bottomBorder = _borders.bottomBorder;
        leftChildBorders.upperBorder = rightChildBorders.upperBorder = _borders.upperBorder;
        leftChildBorders.rightBorder = rightChildBorders.leftBorder = splitPosition;
        leftChildBorders.leftBorder = _borders.leftBorder;
        rightChildBorders.rightBorder = _borders.rightBorder;

        leftChildSize = splitPosition - _borders.leftBorder - 1;
        rightChildSize = _borders.rightBorder - splitPosition - 1;
    }
    if (leftChildSize < MIN_ROOM_SIZE or rightChildSize < MIN_ROOM_SIZE)
    {
        return false;
    }
    _leftChild = std::make_shared<Room>(leftChildBorders);
    _rightChild = std::make_shared<Room>(rightChildBorders);
    return true;
}

SplitDirection Room::calculateSplitDirection()
{
    unsigned width = _borders.rightBorder - _borders.leftBorder - 1;
    unsigned height = _borders.upperBorder - _borders.bottomBorder - 1;
    SplitDirection splitDirection;
    if (width > height)
    {
        splitDirection = SplitDirection::Vertical;
    }
    else if (height > width)
    {
        splitDirection = SplitDirection::Horizontal;
    }
    else
    {
        splitDirection = random(0, 1) ? SplitDirection::Vertical : SplitDirection::Horizontal;
    }
    return splitDirection;
}

int Room::calculateSplitPosition(const SplitDirection& splitDirection)
{
    bool horizontalSplit = (splitDirection == SplitDirection::Horizontal);

    int min = ((horizontalSplit) ? _borders.bottomBorder : _borders.leftBorder) + MIN_ROOM_SIZE + 1;
    int max = ((horizontalSplit) ? _borders.upperBorder : _borders.rightBorder) - MIN_ROOM_SIZE - 1;

    return random(min, max);
}

const std::shared_ptr<Room>& Room::getLeftChild()
{
    return _leftChild;
}
const std::shared_ptr<Room>& Room::getRightChild()
{
    return _rightChild;
}

const RoomBorders& Room::getRoomBorders()
{
    return _borders;
}
