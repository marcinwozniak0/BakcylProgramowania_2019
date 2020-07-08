#pragma once
#include "Table.hpp"
#include "Player.hpp"

//Klasa walki, jej obiekt jest tworzony za każdym razem, gdy gracz wejdzie na pole z walką;
//Cała procedura będzie zawierać w sobie init(), action() i cleanup();
//Będzie potrzebować dwóch graczy;
//Zawierać będzie w sobie stół(aby móc działać na kartach tam będących);
//Potzebne metody to printFight(),endRound(), operacje na kartach;
//W jakims nadrzędnym pliku wywoływane są te funkcje w pętli i sprawdzane jest czy obaj playerzy nadal żyją
//TODO w Playerze bool isAlive;

class Fight//pola i metody do posegregowania
{
public:
//init():
Fight(Player p1, Player p2);
Table _table;
//action():
void printFight();
void splitDamage();
void handleInput();
void continueFight();
//cleanup();
void splitRewards();
void deleteFightObjects();
void printEndGame();
void cleanFight();
};
