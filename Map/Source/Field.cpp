#include "Field.hpp"

Field::Field(char sym)
{
    symbol = sym;
}

char Field::getType() const
{
    return symbol;
}
