#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <memory>

using Card = std::string;

class Deck
{
public:
  std::vector<Card> _cards;
  uint findCard(Deck deckToSearch, Card cardToFind);
  void addCard(Card cardToAdd);
  Card moveCard(Deck &ToThisDeck, Card cardToMove);
  void shuffleCards();
  std::unique_ptr<Card> removeCard(Card cardToRemove);
};
