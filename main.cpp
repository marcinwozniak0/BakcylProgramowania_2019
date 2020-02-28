#include <iostream>
#include <cstdint>
/*
enum class Result
{
   ADDED_SUCCESSFULLY,
   ADDED_TO_MAX,
   REMOVED_SUCESSFULLY,
   REMOVED_TO_ZERO
};
*/
struct Points
{
   uint _maxPoints;
   uint _currentPoints;

   Points(const uint maxPoints)
   {
      _maxPoints = maxPoints;
      _currentPoints = maxPoints;
   }

   void remove(const uint amount)
   {
      if(amount > _currentPoints)
      {
         _currentPoints = 0;
      }

      _currentPoints -= amount;
   }

   void add(const uint amount)
   {
      if(_currentPoints + amount > _maxPoints)
      {
         _currentPoints += amount;
      }

      _currentPoints += amount;
   }

   void alignMaxTo (const uint amount)
   {
      _maxPoints = amount;
   }

   void resetCurrent()
   {
      _currentPoints = _maxPoints;
   }

   //TODO RESET MAX-------------------------

};

using HP = Points;
using MP = Points;

struct Player
{
   HP _HP;
   MP _MP;

   Player(Points HP, Points MP)
      : _HP(HP)
      , _MP(MP)
   {}
};

int main()
{
   Player p(100, 100);

   std::cout << "Kaczka!" << std::endl;
	return 0;
}
