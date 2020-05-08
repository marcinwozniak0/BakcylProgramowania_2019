#include "Deck.hpp"

uint Deck::findCard(Card& cardToFind) try
{
  for(uint i = 0; i < this->_cards.size(); ++i)
  {
    if(this->_cards.at(i) == cardToFind)
    {
      return i;
    }
  }
  throw std::runtime_error("Card not found");
}
catch (std::runtime_error& exception)
{
  std::cout << exception.what();
  return false;
}

void Deck::addCard(Card cardToAdd)
{
  _cards.push_back(cardToAdd);
}

void Deck::shuffleCards()
{
  std::random_shuffle (_cards.begin(), _cards.end());
}

Card Deck::moveCard(Deck &ToThisDeck,Card cardToMove)
{
    uint cardIndex = findCard(cardToMove);
    ToThisDeck._cards.push_back(this->_cards.at(cardIndex));
    removeCard(cardToMove);
    return cardToMove;
}

std::unique_ptr<Card> Deck::removeCard(Card cardToRemove)
{
  std::unique_ptr<Card> removedCard;
  if(_cards.size() <= 0)
  {
    std::cout << "Váš balíček karet je prázdný";
  }
  else
  {
      uint cardIndex = findCard(cardToRemove);
      removedCard = std::make_unique<Card> (this->_cards.at(cardIndex));
      this->_cards.erase(this->_cards.begin() + cardIndex);
  }
  return removedCard;
}

std::unique_ptr<Card> Deck::removeFirstCard()
{
  std::unique_ptr<Card> removedCard;
  if(_cards.size() <= 0)
  {
    std::cout << "Váš balíček karet je prázdný";
  }
  else
  {
    removedCard = std::make_unique<Card> (this->_cards.at(0));
    this->_cards.erase(this->_cards.begin());
  }
  return removedCard;
}
