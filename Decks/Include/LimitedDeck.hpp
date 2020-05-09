#pragma once
#include "Deck.hpp"

class TableDeck : public Deck
{
public:
  uint _maxSize;
  TableDeck(uint maxSize);
};

class HandDeck : public Deck
{
public:
  uint _maxSize;
  HandDeck(uint maxSize);
  void drawCard(Deck &deck);
  void playCard(std::shared_ptr<TableDeck> tableDeckPointer, Card CardToThrow);
};
