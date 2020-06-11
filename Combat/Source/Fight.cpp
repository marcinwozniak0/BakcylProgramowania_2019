#include "Fight.hpp"

void Fight:printEndGame() const
{
  //TODO NCURSES
}

void Fight::printFight(Player* p1, Player* p2) const
{
  while(*p1.życie > 0 || *p2.życie > 0)
  {
    //TODO NCURSES
  }
  printEndGame();
}

