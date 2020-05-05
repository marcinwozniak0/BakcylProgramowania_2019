#include "Deck.hpp"

uint findCard(Deck deckToSearch, Card cardToFind)
{
  for(uint i = 0; i < deckToSearch._cards.size(); ++i)
  {
    if(deckToSearch._cards.at(i) == cardToFind)
    {
      return i;
    }
  }
  return 0;
  // TODO wyjątek (execption)
}

void Deck::addCard(Card cardToAdd)
{
  _cards.push_back(cardToAdd);
}

void Deck::shuffleCards()
{
  std::random_shuffle (_cards.begin(), _cards.end());
}

Card Deck::moveCard(Deck &ToThisDeck, Card cardToMove)
{
    uint cardIndex = findCard(*this, cardToMove);
    ToThisDeck._cards.push_back(_cards.at(cardIndex));
    _cards.erase(_cards.begin() + cardIndex);
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
      uint cardIndex = findCard(*this, cardToRemove);
      removedCard = std::make_unique<Card> (_cards.at(cardIndex));
      _cards.erase(_cards.begin() + cardIndex);
  }
  return removedCard;
}
