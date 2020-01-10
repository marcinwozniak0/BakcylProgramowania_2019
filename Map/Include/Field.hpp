#pragma once

class Field
{
public:
    virtual void action() = 0;
    virtual char getType() const = 0;
};
