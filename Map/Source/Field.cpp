#include "Field.hpp"

bool Field::isVisible() const
{
    return _isVisible;
}
void Field::makeVisible()
{
    _isVisible = true;
}
