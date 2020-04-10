#include "Handdeck.hpp"

HandDeck::HandDeck(int maxSize)
:_maxSize(maxSize)
{

}

void Deck::addCard(Card cardToAdd)
{
  _cards.push_back(cardToAdd);
}

void Deck::shuffleCards()
{
  std::random_shuffle (_cards.begin(), _cards.end());
}

void HandDeck::drawCard(Deck &deck)
{
  if(_size >= _maxSize)
  {
    std::cout << "Vaše ruka je plná" << std::endl;
  }
  else
  {
    _cards.push_back(deck._cards.at(0));
    deck._cards.erase(deck._cards.begin());
    ++_size;
  }
}


Card Deck::discardCard(Deck &deck, Card cardToDiscard)
{
  for(uint i = 0; i < _cards.size(); ++i)
  {
    if(_cards.at(i) == cardToDiscard)
    {
      deck._cards.push_back(_cards.at(i));
      _cards.erase(_cards.begin() + i);
    }
  }
  return cardToDiscard;
}
