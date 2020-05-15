#include "Points.hpp"
#include <cstdlib>

Points::Points(const uint maxPoints)
   : _maxPoints(maxPoints), _currentPoints(maxPoints)
{}

Points::Points(const uint maxPoints, const uint currentPoints)
   : _maxPoints(maxPoints)
{
      if(currentPoints > maxPoints)
      {
         //TODO throw exception
         _currentPoints = maxPoints;
      }
      else
      {
         _currentPoints = currentPoints;
      }
}

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
   _currentPoints += amount;
   if(_currentPoints > _maxPoints)
   {
      _currentPoints = _maxPoints;
   }
}

void Points::setMaxTo (const uint amount)
{
   _maxPoints = amount;
}

uint Points::getMaxPoints() const
{
    return _maxPoints;
}

void Points::resetCurrent()
{
   _currentPoints = _maxPoints;
}

void Points::setCurrentPoints(const uint newValue)
{
  _currentPoints = newValue;
  if(_currentPoints > _maxPoints)
  {
     _currentPoints = _maxPoints;
  }
}

uint Points::getCurrentPoints() const
{
  return _currentPoints;
}

const bool operator== (const Points& lhs, const Points& rhs)
{
   return lhs.getCurrentPoints() == rhs.getCurrentPoints();
}

const bool operator!= (const Points& lhs, const Points& rhs)
{
   return !(lhs == rhs);
}

const bool operator> (const Points& lhs, const Points& rhs)
{
   return lhs.getCurrentPoints() > rhs.getCurrentPoints();
}

const bool operator>= (const Points& lhs, const Points& rhs)
{
   return lhs.getCurrentPoints() >= rhs.getCurrentPoints();
}

const bool operator< (const Points& lhs, const Points& rhs)
{
   return !(lhs >= rhs);
}

const bool operator<= (const Points& lhs, const Points& rhs)
{
   return !(lhs > rhs);
}

const Points operator+ (const Points& lhs, const Points& rhs)
{
   return Points(lhs.getCurrentPoints() + rhs.getCurrentPoints());
}

const Points operator- (const Points& lhs, const Points& rhs)
{
   uint currentPoints = 0;

   if(lhs.getCurrentPoints() > rhs.getCurrentPoints())
   {
      currentPoints = lhs.getCurrentPoints() - rhs.getCurrentPoints();
   }

   return Points(lhs.getMaxPoints(), currentPoints);
}
