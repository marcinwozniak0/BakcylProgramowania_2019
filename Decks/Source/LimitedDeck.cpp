#include "LimitedDeck.hpp"

HandDeck::HandDeck(uint maxSize)
{
  _maxSize = maxSize;
}

TableDeck::TableDeck(uint maxSize)
{
  _maxSize = maxSize;
}


void HandDeck::drawCard(Deck &deck)
{
  if(cards->size() >= _maxSize)
  {
    std::cout << "Vaše ruka je plná" << std::endl;
  }
  else
  {
    cards->push_back(deck.cards->at(0));
    deck.removeFirstCard();
  }
}

void HandDeck::playCard(std::shared_ptr<TableDeck> tableDeckPointer, Card CardToThrow)
{
  if(tableDeckPointer->cards->size() >= tableDeckPointer->_maxSize)
  {
    std::cout << "Váš stůl je již plný" << std::endl;
  }
  else
  {
    uint cardIndex = findCard(CardToThrow);
    tableDeckPointer->cards->push_back(this->cards->at(cardIndex));
    removeCard(CardToThrow);
  }
}
