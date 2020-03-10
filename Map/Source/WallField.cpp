#include "WallField.hpp"

WallField::WallField()
{
    _isVisible = true;
}
void WallField::action()
{

}

FieldType WallField::getType() const
{
	return FieldType::Wall;
}
