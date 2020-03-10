#pragma once

#include "Field.hpp"

class WallField : public Field
{
public:
    WallField();
    void action();
    FieldType getType() const;
};
