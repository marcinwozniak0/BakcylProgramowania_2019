#include <iostream>
#include <cstdint>
#include "Points.hpp"

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
