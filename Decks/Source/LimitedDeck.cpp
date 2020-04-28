#include "LimitedDeck.hpp"

HandDeck::HandDeck(int maxSize)
:_maxSize(maxSize)
{

}

TableDeck::TableDeck(int maxSize)
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

void TableDeck::playCard(HandDeck &deck, TableDeck &toThistable, Card CardToThrow)
{
  if(_size >= _maxSize)
  {
    std::cout << "Váš stůl je již plný" << std::endl;
  }
  else
  {
    for(uint i = 0; i < deck._cards.size(); ++i)
    {
      if(deck._cards.at(i) == CardToThrow)
      {
        toThistable._cards.push_back(_cards.at(i));
        toThistable._cards.erase(_cards.begin() + i);
      }
    }
    ++_size;
  }
}
