#include "Points.hpp"

Points::Points(const uint maxPoints)
{
   _maxPoints = maxPoints;
   _currentPoints = maxPoints;
}

void Points::remove(const uint amount)
{
   if(amount > _currentPoints)
   {
      _currentPoints = 0;
   }

   _currentPoints -= amount;
}

void Points::add(const uint amount)
{
   if(_currentPoints + amount > _maxPoints)
   {
      _currentPoints += amount;
   }

   _currentPoints += amount;
}

void Points::alignMaxTo (const uint amount)
{
   _maxPoints = amount;
}

void Points::resetCurrent()
{
   _currentPoints = _maxPoints;
}

//Operators
bool operator == (const Points& lhs, const Points& rhs)
{
   return lhs._currentPoints == rhs._currentPoints && lhs._maxPoints == rhs._maxPoints;
}

bool operator != (const Points& lhs, const Points& rhs)
{
   return !(lhs == rhs);
}