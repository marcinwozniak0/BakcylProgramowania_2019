#pragma once
#include <vector>
#include "Field.hpp"
#include <memory>

class Room
{
public:
    virtual std::vector<std::shared_ptr<Field>> getFields() = 0;
};
