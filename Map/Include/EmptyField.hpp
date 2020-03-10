#pragma once
#include "Field.hpp"

class EmptyField : public Field
{
public:
    EmptyField();
    void action();
    FieldType getType() const;
};
