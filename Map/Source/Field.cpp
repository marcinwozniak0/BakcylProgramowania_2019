#include "Field.hpp"

Field::Field() : _isVisible(false)
{
}
bool Field::isVisible() const
{
    return _isVisible;
}
void Field::makeVisible()
{
    _isVisible = true;
}
