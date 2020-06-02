#include <iostream>
#include <cstdint>
#include "Points.hpp"
#include "LimitedDeck.hpp"

using HP = Points;
using MP = Points;

struct Player
{
   HP _HP;
   MP _MP;
   HandDeck _playersHanddeck;
   Deck _playersPulldeck;

   Player(Points HP, Points MP, int Handdeck_size)
      : _HP(HP)
      , _MP(MP)
      , _playersHanddeck(Handdeck_size)
   {}
};

int main()
{
   Player p1(100, 100, 5);

   std::cout << "Kaczka!" << std::endl;
	return 0;
}
