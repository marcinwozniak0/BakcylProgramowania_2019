#include "EmptyField.hpp"

EmptyField::EmptyField()
{
    _isVisible = false;
}
void EmptyField::action()
{
}

FieldType EmptyField::getType() const
{
    return FieldType::Empty;
}
