#pragma once

#include "Field.hpp"

class WallField :public Field
{
public:
    void action();
    FieldType getType() const;
};