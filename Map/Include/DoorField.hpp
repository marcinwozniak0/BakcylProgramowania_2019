#pragma once
#include "Field.hpp"

class DoorField :public Field
{
public:
    void action();
    FieldType getType() const;
};
