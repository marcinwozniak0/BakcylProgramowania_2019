#include "Fight.hpp"

Fight::Fight(Player p1, Player p2)
{

}

void printFight()
{
  //Printowanie ncurses menu
}

void handleInput()
{
  //zbieranie inputu z klawiatury gracza
}

void splitDamage()
{

}

void continueFight()
{
 printFight();
 handleInput();
 splitDamage();
 //metoda wywołująca się co turę
}

void splitRewards()
{

}

void deleteFightObjects()
{
  // destruktory obiektów, czyszczenie decków, stółu
}

void printEndGame()
{

}

void cleanFight()
{
 splitRewards();
 deleteFightObjects();
 printEndGame();
}
