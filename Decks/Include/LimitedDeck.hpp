#pragma once
#include "Deck.hpp"

class TableDeck : public Deck
{
  uint _maxSize;
  //int _currentDeckFill = 0;
public:
  TableDeck(uint maxSize);
};

class HandDeck : public Deck
{
  uint _maxSize;
  //int _currentDeckFill = 0;
public:
  HandDeck(uint maxSize);
  void drawCard(Deck &deck);
  void playCard(TableDeck &toThisDeck, Card CardToThrow);
};
