#pragma once
#include "Deck.hpp"

class TableDeck : public Deck
{
public:
  TableDeck(uint maxSize);
};

class HandDeck : public Deck
{
public:
  void drawCard(Deck &deck);
  void playCard(std::shared_ptr<TableDeck> tableDeckPointer, Card CardToThrow);
  HandDeck(uint maxSize);
};
