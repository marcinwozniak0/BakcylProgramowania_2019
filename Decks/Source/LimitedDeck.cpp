#include "LimitedDeck.hpp"

HandDeck::HandDeck(uint maxSize)
  :_maxSize(maxSize)
{

}

TableDeck::TableDeck(uint maxSize)
  :_maxSize(maxSize)
{

}

void HandDeck::drawCard(Deck &deck)
{
  if(_cards.size() >= _maxSize)
  {
    std::cout << "Vaše ruka je plná" << std::endl;
  }
  else
  {
    _cards.push_back(deck._cards.at(0));
    deck._cards.erase(deck._cards.begin());
  }
}

void HandDeck::playCard(TableDeck &toThisDeck, Card CardToThrow)
{
//   if(_cards.size() >= _maxSize)
//   {
//     std::cout << "Váš stůl je již plný" << std::endl;
//   }
//   else
//   {
//     uint cardIndex = findCard(CardToThrow);
//     toThisDeck._cards.push_back(_cards.at(cardIndex));
//     removeCard(Card cartToRemove);
//   }
// toThisDeck._cards.push_back(_cards.at(i));
}
