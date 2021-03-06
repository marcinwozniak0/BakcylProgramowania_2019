#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <exception>
#include <stdexcept>
#include <climits>
#include "Card.hpp"

class Deck
{
protected:
  std::vector<Card> _cards;
  uint _maxSize;
public:
  uint findCard(Card& cardToFind);
  void addCard(Card cardToAdd);
  Card moveCard(Deck &ToThisDeck, Card cardToMove);
  void shuffleCards();
  uint getSize();
  std::shared_ptr<Card> removeCard(Card &cardToRemove);
  std::shared_ptr<Card> removeFirstCard();
  std::shared_ptr<std::vector<Card>> cards;
  uint getMaxSize();
  Deck();
};
