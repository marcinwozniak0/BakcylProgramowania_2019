#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


using Card = std::string;

class Deck
{
public:
  std::vector<Card> Cards;
  void addCard(Card cardToAdd);
};

class DiscardDeck :public Deck
{
public:
  int maxSize;
  DiscardDeck(int _maxSize);
};

class PullDeck :public Deck
{
public:
  int maxSize;
  PullDeck(int _maxSize);
};

class TableDeck :public Deck
{
public:
  int tableSize;
  TableDeck(int _tableSize);
};

class HandDeck :public Deck
{
  int startSize;
  int rng = 0;
public:
  HandDeck(int _startSize);
  void drawCard(PullDeck &pullDeck);
  void playCard(TableDeck &tableDeck, Card cardToPlay);
  void discardCard(DiscardDeck &discardDeck, Card cardToDiscard);
};
