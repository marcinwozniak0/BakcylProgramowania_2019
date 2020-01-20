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
    Field(){
        printability = false;
    }
    bool isPrintable(){
        return printability;
    }
    void makePrintable(){
        printability = true;
    }
    virtual void action() = 0;
    virtual FieldType getType() const = 0;

protected:
    Neighbours _neighbours;
    virtual Neighbours& getNeighbours() {return _neighbours;}
    bool printability;
};
