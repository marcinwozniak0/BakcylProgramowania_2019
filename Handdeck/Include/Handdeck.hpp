#pragma once
#include "Deck.hpp"

class HandDeck : public Deck
{
  int _maxSize;
  int _size = 0;
public:
  HandDeck(int maxSize);
  void drawCard(Deck &deck);
};
