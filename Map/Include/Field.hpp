#pragma once
#include "FieldTypes.hpp"
#include <memory>

class Field;

struct Neighbours
{
    std::shared_ptr<Field> up;
    std::shared_ptr<Field> down;
    std::shared_ptr<Field> left;
    std::shared_ptr<Field> right;
};

class Field
{
public:
    Field();
    bool isVisible();
    void makeVisible();

    virtual void action() = 0;
    virtual FieldType getType() const = 0;

protected:
    Neighbours _neighbours;
    virtual Neighbours& getNeighbours() {return _neighbours;}

private:
    bool _isVisible;
};
