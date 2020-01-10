#pragma once
#include "Field.hpp"

class EmptyField : public Field
{
public:
    void action();
    FieldType getType() const;
};