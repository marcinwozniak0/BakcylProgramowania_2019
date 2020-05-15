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
  Card moveCard(Deck &ToThisDeck, Card cardToMove);
  void shuffleCards();
};
