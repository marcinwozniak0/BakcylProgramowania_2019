#pragma once
#include "Field.hpp"

class TreasureField : public Field
{
public:
    FieldType getType() const;
    void action();
};