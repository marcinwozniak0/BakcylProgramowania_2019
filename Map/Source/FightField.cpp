#include "FightField.hpp"

FightField::FightField()
{
    _isVisible = false;
}

void FightField::action()
{

}

FieldType FightField::getType() const
{
    return FieldType::Fight;
}
