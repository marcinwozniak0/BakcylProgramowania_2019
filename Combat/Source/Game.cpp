#include "Game.hpp"


void GameControler::cleanCards(Deck& deck){
  //deck.erase(deck.begin(),deck.end());
  deck.clear();
}

void GameControler::cleanUP(Deck& deck){
  cleanCards(deck);
}
