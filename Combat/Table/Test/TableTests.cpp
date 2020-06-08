#include "Table.hpp"
#include <gtest/gtest.h>
#include "CardPool.hpp"

using namespace ::testing;

static CardPool cardpoolTEST;

TEST(LimitOfCardsOnTable, ItShouldWarnPlayerAboutTryOfPassingLimitOfCardsOnTableAndDiscardDeck)
{
  Table table1;
  HandDeck handdeck1(10);

  handdeck1.addCard(cardpoolTEST._monsterCardPool[0]);
  handdeck1.addCard(cardpoolTEST._monsterCardPool[1]);
  handdeck1.addCard(cardpoolTEST._monsterCardPool[2]);
  handdeck1.addCard(cardpoolTEST._monsterCardPool[3]);
  handdeck1.addCard(cardpoolTEST._monsterCardPool[4]);
  handdeck1.addCard(cardpoolTEST._monsterCardPool[5]);

  handdeck1.playCard(table1.playersTableSite, handdeck1.cards->at(0));
  handdeck1.playCard(table1.playersTableSite, handdeck1.cards->at(0));
  handdeck1.playCard(table1.playersTableSite, handdeck1.cards->at(0));
  handdeck1.playCard(table1.playersTableSite, handdeck1.cards->at(0));
  handdeck1.playCard(table1.playersTableSite, handdeck1.cards->at(0));
  handdeck1.playCard(table1.playersTableSite, handdeck1.cards->at(0));

  ASSERT_EQ(5, table1.playersTableSite->cards->size());
  ASSERT_EQ(1, handdeck1.cards->size());
}

TEST(TransferingCardsToDiscardDeck, ItShouldtransferCardsFromTableDeckToDiscardDeck)
{
  Table table1;

  table1.playersTableSite -> addCard(cardpoolTEST._monsterCardPool[0]);
  table1.playersTableSite -> addCard(cardpoolTEST._monsterCardPool[1]);
  table1.playersTableSite -> addCard(cardpoolTEST._monsterCardPool[2]);
  table1.playersTableSite -> addCard(cardpoolTEST._monsterCardPool[3]);
  table1.playersTableSite -> addCard(cardpoolTEST._monsterCardPool[4]);

  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, cardpoolTEST._monsterCardPool[0]);
  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, cardpoolTEST._monsterCardPool[1]);
  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, cardpoolTEST._monsterCardPool[2]);
  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, cardpoolTEST._monsterCardPool[3]);
  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, cardpoolTEST._monsterCardPool[4]);

  ASSERT_EQ(5, table1._playersDiscardDeck.cards->size());
  ASSERT_EQ(0, table1._playersTableSite.cards->size());
}
