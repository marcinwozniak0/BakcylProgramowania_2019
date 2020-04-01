#pragma once
#include "Field.hpp"

class FightField :public Field
{
public:
    void action();
    FieldType getType() const;
};