#include "Deck.hpp"

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
  for(uint i = 0; i < _cards.size(); ++i)
  {
    if(_cards.at(i) == cardToMove)
    {
      ToThisDeck._cards.push_back(_cards.at(i));
      _cards.erase(_cards.begin() + i);
    }
  }
  return cardToMove;
}
