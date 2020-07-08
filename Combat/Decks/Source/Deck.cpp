#include "Deck.hpp"

Deck::Deck()
  : _maxSize(UINT_MAX), cards(std::make_shared<std::vector<Card>>(_cards))
{

}


uint Deck::findCard(Card& cardToFind)
{
  auto it = std::find(this->cards->begin(), this->cards->end(), cardToFind);
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
  uint cardIndex = findCard(cardToMove);
  ToThisDeck.cards->push_back(this->cards->at(cardIndex));
  removeCard(cardToMove);
  return cardToMove;
}

std::shared_ptr<Card> Deck::removeCard(Card &cardToRemove)
{
  if(cards->size() <= 0)
  {
    std::cout << "Váš balíček karet je prázdný";
    throw std::overflow_error("too small");
  }
  else
  {
    uint cardIndex = findCard(cardToRemove);
    std::shared_ptr<Card> ptr = std::make_shared<Card>(std::move(this->cards->at(cardIndex)));
    this->cards->erase(this->cards->begin() + cardIndex);
    return ptr;
  }
}

std::shared_ptr<Card> Deck::removeFirstCard()
{
  if(cards->size() <= 0)
  {
    std::cout << "Váš balíček karet je prázdný";
    throw std::overflow_error("too small");
  }
  else
  {
    std::shared_ptr<Card> ptr = std::make_shared<Card>(std::move(this->cards->at(0)));
    this->cards->erase(this->cards->begin());
    return ptr;
  }
}

uint Deck::getMaxSize()
{
 return this->_maxSize;
}

uint Deck::getSize()
{
 return this->cards->size();
}
