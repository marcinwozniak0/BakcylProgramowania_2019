#pragma once
#include <iostream>
#include <cstdint>

struct Points
{
   uint _maxPoints;
   uint _currentPoints;

   Points(const uint maxPoints);
   void remove(const uint amount);
   void add(const uint amount);
   void alignMaxTo (const uint amount);
   void resetCurrent();
};

//Operators
bool operator == (const Points& lhs, const Points& rhs);
bool operator != (const Points& lhs, const Points& rhs);
