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
  Card addCard(Card cardToAdd);
};

class DiscardDeck :public Deck
{
public:
  DiscardDeck();
};

class PullDeck :public Deck    //33 karty w sumie
{
public:
  int maxSize;
  PullDeck(int _maxSize);
};

class TableDeck :public Deck    //33 karty w sumie
{
public:
  int tableSize;
  TableDeck(int _tableSize);
};

class HandDeck :public Deck
{
  int startSize;
  int rng;
public:
  HandDeck(int _startSize);
  Card drawCard(PullDeck pullDeck);
  Card playCard(TableDeck tableDeck, Card cardToPlay);
  Card discardCard(DiscardDeck discardDeck, Card cardToDiscard);
};
