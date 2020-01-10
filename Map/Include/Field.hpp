#pragma once
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
    virtual void action() = 0;
    virtual char getType() const = 0;
protected:
    Neighbours _neighbours;
    virtual Neighbours& getNeighbours() {return _neighbours;}
};
