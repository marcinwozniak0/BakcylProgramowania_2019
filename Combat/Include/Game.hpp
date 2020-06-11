#pragma once
#include "Player.hpp"
#include <vector>
#include <string>

using Deck = std::vector<std::string>;

class GameControler
{
  public :
//  GameControler();
  void init();
// init
// 1. stworzenie  Playera
// 2. Dać jaką gra profesją
// 4. Wywołanie funkcji która stworzy table
  void action();
// 1. utowrzenie tury(wykonanie ruchu przez gracza)
// 2. zakończenie ruchu poprzedniego gracza i tym samym rozpoczęcie ruchu drugiego
  void cleanUP(Deck& deck);
  void cleanCards(Deck& deck);
  // kończy rozgrywkę "sprząta stół"(system "cls")
};
