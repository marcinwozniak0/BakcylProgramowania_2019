#include "DoorField.hpp"

DoorField::DoorField() 
{
    _isVisible = true;
}
void DoorField::action()
{
}

FieldType DoorField::getType() const
{
    return FieldType::Door;
}
