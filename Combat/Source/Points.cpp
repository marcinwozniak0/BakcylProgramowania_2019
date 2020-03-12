#include "Points.hpp"
#include <cstdlib>

Points::Points(const uint maxPoints)
{
   _maxPoints = maxPoints;
   _currentPoints = maxPoints;
}

Points::Points(const uint maxPoints, const uint currentPoints)
{
      _maxPoints = maxPoints;
      _currentPoints = currentPoints;
}

// Sprawdzanie na karcie czy currentMP >= amount
void Points::remove(const uint amount)
{
   if(amount > _currentPoints)
   {
      _currentPoints = 0;
   }
   else
   {
      _currentPoints -= amount;
   }
}

void Points::add(const uint amount)
{
   if(_currentPoints + amount > _maxPoints)
   {
      _currentPoints = _maxPoints;
   }
   else
   {
   _currentPoints += amount;
   }
}

void Points::setMaxTo (const uint amount)
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
   return lhs._currentPoints == rhs._currentPoints;
}

bool operator != (const Points& lhs, const Points& rhs)
{
   return !(lhs == rhs);
}

bool operator > (const Points& lhs, const Points& rhs)
{
   return lhs._currentPoints > rhs._currentPoints;
}

bool operator >= (const Points& lhs, const Points& rhs)
{
   return lhs._currentPoints >= rhs._currentPoints;
}

bool operator < (const Points& lhs, const Points& rhs)
{
   return !(lhs >= rhs);
}

bool operator <= (const Points& lhs, const Points& rhs)
{
   return !(lhs > rhs);
}

Points operator + (const Points& lhs, const Points& rhs)
{
   return Points(lhs._maxPoints + rhs._maxPoints, lhs._currentPoints + rhs._currentPoints);
}

Points operator - (const Points& lhs, const Points& rhs)
{
   uint maxPoints = 0;
   uint currentPoints = 0;

   if(lhs._maxPoints > rhs._maxPoints)
   {
      maxPoints = lhs._maxPoints - rhs._maxPoints;
   }

   if(lhs._currentPoints > rhs._currentPoints)
   {
      currentPoints = lhs._currentPoints - rhs._currentPoints;
   }

   return Points(maxPoints, currentPoints);
}
