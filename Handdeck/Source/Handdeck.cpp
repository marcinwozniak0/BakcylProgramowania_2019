#include "Handdeck.hpp"

HandDeck::HandDeck(int _startSize)
:
startSize(_startSize)
{

}

TableDeck::TableDeck(int _tableSize)
:
tableSize(_tableSize)
{

}

DiscardDeck::DiscardDeck(int _maxSize)
:
maxSize(_maxSize)
{

}


PullDeck::PullDeck(int _maxSize)
:
maxSize(_maxSize)
{

}

void Deck::addCard(Card cardToAdd)
{
  Cards.push_back(cardToAdd);
}

void HandDeck::drawCard(PullDeck &pullDeck)
{
  srand( time( NULL ) );
  rng = ( std::rand() % pullDeck.Cards.size());
  Cards.push_back(pullDeck.Cards.at(rng));
  pullDeck.Cards.erase(pullDeck.Cards.begin() + rng);
}


void TableDeck::discardCard(DiscardDeck &discarddeck, Card cardToDiscard)
{
  for(uint i = 0; i < Cards.size(); ++i)
  {
    if(Cards.at(i) == cardToDiscard)
    {
      discarddeck.Cards.push_back(Cards.at(i));
      Cards.erase(Cards.begin() + i);
    }
  }
}

void HandDeck::playCard(TableDeck &tableDeck, Card cardToPlay)
{
  for(uint i = 0; i < Cards.size(); ++i)
  {
    if(Cards.at(i) == cardToPlay)
    {
      tableDeck.Cards.push_back(Cards.at(i));
      Cards.erase(Cards.begin() + i);
    }
  }
}
