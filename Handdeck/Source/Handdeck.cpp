#include "Handdeck.hpp"

HandDeck::HandDeck(int maxSize)
:_maxSize(maxSize)
{

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
