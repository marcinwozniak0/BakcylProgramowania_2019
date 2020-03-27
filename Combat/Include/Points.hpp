#pragma once
#include <cstdlib>

struct Points
{
   uint _maxPoints;
   uint _currentPoints;

   Points(const uint maxPoints);
   Points(const uint maxPoints, const uint currentPoints);
   void remove(const uint amountToRemove);
   void add(const uint amountToAdd);
   void setMaxTo (const uint newValue);
   void resetCurrent();
};

const bool operator== (const Points& lhs, const Points& rhs);
const bool operator!= (const Points& lhs, const Points& rhs);
const bool operator> (const Points& lhs, const Points& rhs);
const bool operator>= (const Points& lhs, const Points& rhs);
const bool operator< (const Points& lhs, const Points& rhs);
const bool operator<= (const Points& lhs, const Points& rhs);
const Points operator+ (const Points& lhs, const Points& rhs);
const Points operator- (const Points& lhs, const Points& rhs);
