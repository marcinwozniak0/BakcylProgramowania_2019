#pragma once
#include "Deck.hpp"

class TableDeck : public Deck
{
  uint _maxSize;

public:
  TableDeck(uint maxSize);
};

class HandDeck : public Deck
{
  uint _maxSize;
public:
  HandDeck(uint maxSize);
  void drawCard(Deck &deck);
  void playCard(std::shared_ptr<TableDeck> tablePointer, Card CardToThrow);
};
