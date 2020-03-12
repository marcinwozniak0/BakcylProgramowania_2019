#pragma once
#include <cstdlib>

struct Points
{
   uint _maxPoints;
   uint _currentPoints;

   Points(const uint maxPoints = 100);
   Points(const uint maxPoints, const uint currentPoints);
   void remove(const uint amount);
   void add(const uint amount);
   void setMaxTo (const uint amount);
   void resetCurrent();
};

//Operators
bool operator == (const Points& lhs, const Points& rhs);
bool operator != (const Points& lhs, const Points& rhs);
Points operator + (const Points& lhs, const Points& rhs);
Points operator - (const Points& lhs, const Points& rhs);
