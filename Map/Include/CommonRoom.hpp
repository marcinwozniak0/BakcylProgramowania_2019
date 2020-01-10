#pragma once
#include "Room.hpp"

class CommonRoom :public Room
{
public:
    std::vector<std::shared_ptr<Field>> getFields();
    CommonRoom(const int size);
private:
    std::vector<std::shared_ptr<Field>> _fields;
};