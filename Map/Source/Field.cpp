#include "Field.hpp"

Field::Field() : printability(false)
{
}
bool Field::isPrintable()
{
    return printability;
}
void Field::makePrintable()
{
    printability = true;
}
