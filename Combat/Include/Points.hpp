#pragma once
#include <cstdlib>

class Points
{
   uint _maxPoints;
   uint _currentPoints;
public:
   Points(const uint maxPoints);
   Points(const uint maxPoints, const uint currentPoints);
   void remove(const uint amountToRemove);
   void add(const uint amountToAdd);
   void setMaxTo (const uint newValue);
   uint getMaxPoints() const;
   void resetCurrent();
   void setCurrentPoints(const uint newValue);
   uint getCurrentPoints() const;
};

const bool operator== (const Points& lhs, const Points& rhs);
const bool operator!= (const Points& lhs, const Points& rhs);
const bool operator> (const Points& lhs, const Points& rhs);
const bool operator>= (const Points& lhs, const Points& rhs);
const bool operator< (const Points& lhs, const Points& rhs);
const bool operator<= (const Points& lhs, const Points& rhs);
const Points operator+ (const Points& lhs, const Points& rhs);
const Points operator- (const Points& lhs, const Points& rhs);
