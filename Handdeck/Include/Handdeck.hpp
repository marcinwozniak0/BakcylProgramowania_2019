#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using Card = std::string;

class Deck
{
public:
  std::vector<Card> _cards;
  void addCard(Card cardToAdd);
  Card discardCard(Deck &deck, Card cardToDiscard);
  void shuffleCards();
};

class HandDeck : public Deck
{
  int _maxSize;
  int _size = 0;
public:
  HandDeck(int maxSize);
  void drawCard(Deck &deck);
};
