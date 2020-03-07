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
