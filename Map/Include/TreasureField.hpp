#pragma once
#include "Field.hpp"

class TreasureField : public Field
{
public:
    TreasureField();
    FieldType getType() const;
    void action();
};
