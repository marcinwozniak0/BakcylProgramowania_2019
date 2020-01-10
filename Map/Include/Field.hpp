#pragma once
#include "FieldTypes.hpp"

class Field
{
public:
    virtual void action() = 0;
    virtual FieldType getType() const = 0;
};
