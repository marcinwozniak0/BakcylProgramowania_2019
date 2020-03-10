#pragma once
#include "Field.hpp"

class FightField :public Field
{
public:
    FightField();
    void action();
    FieldType getType() const;
};
