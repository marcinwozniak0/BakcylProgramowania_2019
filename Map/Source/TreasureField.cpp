#include "TreasureField.hpp"

TreasureField::TreasureField()
{
    _isVisible = false;
}
FieldType TreasureField::getType() const
{
    return FieldType::Treasure;
}

void TreasureField::action()
{
    // action 
}
