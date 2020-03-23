#pragma once
#include "FieldTypes.hpp"
#include <memory>

class Field
{
public:
    Field();
    bool isVisible() const;
    void makeVisible();
    void makeInvisible();

    virtual void action() = 0;
    virtual FieldType getType() const = 0;

private:
    bool _isVisible;
};
