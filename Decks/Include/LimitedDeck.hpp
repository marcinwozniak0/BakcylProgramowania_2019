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

class TableDeck : public Deck
{
  int _maxSize;
  int _size = 0;
public:
  TableDeck(int maxSize);
  void playCard(HandDeck &deck, TableDeck &toThisDeck, Card CardToThrow);
};
