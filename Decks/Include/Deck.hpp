#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <memory>
#include <exception>
#include <stdexcept>

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
  std::unique_ptr<Card> removeCard(Card cardToRemove);
  std::unique_ptr<Card> removeFirstCard();
  std::shared_ptr<std::vector<Card>> cards;

  Deck();
};
