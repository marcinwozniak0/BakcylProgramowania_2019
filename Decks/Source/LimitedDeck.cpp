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
    deck.removeFirstCard();
  }
}

void HandDeck::playCard(std::shared_ptr<TableDeck> tableDeckPointer, Card CardToThrow)
{
  if(tableDeckPointer->_cards.size() >= tableDeckPointer->_maxSize)
  {
    std::cout << "Váš stůl je již plný" << std::endl;
  }
  else
  {
    uint cardIndex = findCard(CardToThrow);
    tableDeckPointer->_cards.push_back(this->_cards.at(cardIndex));
    removeCard(CardToThrow);
  }
}
