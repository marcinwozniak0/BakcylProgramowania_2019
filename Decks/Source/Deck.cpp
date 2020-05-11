#include "Deck.hpp"

Deck::Deck()
{
  cards = std::make_shared<std::vector<Card>>(_cards);
}

uint Deck::findCard(Card& cardToFind)
{
  for(uint i = 0; i < this->cards->size(); ++i)
  {
    if(this->cards->at(i) == cardToFind)
    {
      return i;
    }
  }
  throw std::runtime_error("Card not found");;
}

void Deck::addCard(Card cardToAdd)
{
  cards->push_back(cardToAdd);
}

void Deck::shuffleCards()
{
  std::random_shuffle(cards->begin(), cards->end());
}

Card Deck::moveCard(Deck &ToThisDeck, Card cardToMove)
{
  uint cardIndex = findCard(cardToMove);
  ToThisDeck.cards->push_back(this->cards->at(cardIndex));
  removeCard(cardToMove);
  return cardToMove;
}

std::unique_ptr<Card> Deck::removeCard(Card cardToRemove)
{
  std::unique_ptr<Card> removedCard;
  if(cards->size() <= 0)
  {
    std::cout << "Váš balíček karet je prázdný";
  }
  else
  {
    uint cardIndex = findCard(cardToRemove);
    removedCard = std::make_unique<Card> (this->cards->at(cardIndex));
    this->cards->erase(this->cards->begin() + cardIndex);
  }
  return removedCard;
}

std::unique_ptr<Card> Deck::removeFirstCard()
{
  std::unique_ptr<Card> removedCard;
  if(cards->size() <= 0)
  {
    std::cout << "Váš balíček karet je prázdný";
  }
  else
  {
    removedCard = std::make_unique<Card> (this->cards->at(0));
    this->cards->erase(this->cards->begin());
  }
  return removedCard;
}
