#include <iostream>
#include <cstdint>
#include "Points.hpp"
/*
enum class Result
{
   ADDED_SUCCESSFULLY,
   ADDED_TO_MAX,
   REMOVED_SUCESSFULLY,
   REMOVED_TO_ZERO
};
*/

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
