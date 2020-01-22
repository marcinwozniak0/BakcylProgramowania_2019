#include "Field.hpp"

Field::Field() : _isVisible(false)
{
}
bool Field::isVisible()
{
    return _isVisible;
}
void Field::makeVisible()
{
    _isVisible = true;
}
