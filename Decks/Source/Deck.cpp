#include "Deck.hpp"

Deck::Deck()
{
  cards = std::make_shared<std::vector<Card>>(_cards);
  _maxSize = UINT_MAX;
}


uint Deck::findCard(Card& cardToFind)
{
  std::vector<Card>::iterator it = std::find(this->cards->begin(), this->cards->end(), cardToFind);
  if(it != this->cards->end())
  {
    return std::distance(this->cards->begin(), it);
  }
  else
  {
    throw std::out_of_range("Card not found");
  }
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
  std::vector<Card>::iterator it = std::find(this->cards->begin(), this->cards->end(), cardToMove);
  uint cardIndex = 0;
  if(it != this->cards->end())
  {
    cardIndex = std::distance(this->cards->begin(), it);
  }
  else
  {
    std::cout<<"Card not found"<<std::endl;
  }
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
