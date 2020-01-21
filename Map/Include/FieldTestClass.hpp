#pragma once
#include "Field.hpp"

class FieldTestClass : public Field
{
    void action();
    FieldType getType() const;
};
