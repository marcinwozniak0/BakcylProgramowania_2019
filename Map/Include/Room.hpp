#pragma once
#include <vector>
#include "Field.hpp"

class Room
{
public:
    virtual std::vector<Field> getFields() = 0;
};
