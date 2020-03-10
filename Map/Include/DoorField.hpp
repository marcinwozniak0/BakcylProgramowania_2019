#pragma once
#include "Field.hpp"

class DoorField :public Field
{
public:
    DoorField();
    void action();
    FieldType getType() const;
};
