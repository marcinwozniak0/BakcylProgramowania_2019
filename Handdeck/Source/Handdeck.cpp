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


PullDeck::PullDeck(int _maxSize)
:
maxSize(_maxSize)
{

}

Card Deck::addCard(Card cardToAdd)
{
  Cards.push_back(cardToAdd);
  return cardToAdd;
}

Card HandDeck::drawCard(PullDeck pullDeck)
{
  srand( time( NULL ) );
  rng = ( std::rand() % pullDeck.Cards.size());
  Cards.push_back(pullDeck.Cards.at(rng));
  pullDeck.Cards.erase(pullDeck.Cards.begin() + rng);
  return pullDeck.Cards.at(rng);
}


Card HandDeck::discardCard(DiscardDeck discardDeck, Card cardToDiscard)
{
  for(uint i = 0; i < Cards.size(); ++i)
  {
    if(Cards.at(i) == cardToDiscard)
    {
      discardDeck.Cards.push_back(Cards.at(i));
      Cards.erase(Cards.begin() + i);
    }
  }
  return cardToDiscard;
}

Card HandDeck::playCard(TableDeck tableDeck, Card cardToPlay)
{
  for(uint i = 0; i < Cards.size(); ++i)
  {
    if(Cards.at(i) == cardToPlay)
    {
      tableDeck.Cards.push_back(Cards.at(i));
      Cards.erase(Cards.begin() + i);
    }
  }

  return cardToPlay;
}
