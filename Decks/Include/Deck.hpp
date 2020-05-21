#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <exception>
#include <stdexcept>
#include <climits>

using Card = std::string;

class Deck
{
protected:
  std::vector<Card> _cards;
public:
  uint findCard(Card& cardToFind);
  void addCard(Card cardToAdd);
  Card moveCard(Deck &ToThisDeck, Card cardToMove);
  void shuffleCards();
  Card&& removeCard(Card &cardToRemove);
  Card&& removeFirstCard();
  std::shared_ptr<std::vector<Card>> cards;
  uint _maxSize;
  Deck();
};
