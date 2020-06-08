#include "Table.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(LimitOfCardsOnTable, ItShouldWarnPlayerAboutTryOfPassingLimitOfCardsOnTableAndDiscardDeck)
{
  Table table1;
  HandDeck handdeck1(10);

  handdeck1.addCard("card1");
  handdeck1.addCard("card2");
  handdeck1.addCard("card3");
  handdeck1.addCard("card4");
  handdeck1.addCard("card5");
  handdeck1.addCard("card6");

  handdeck1.playCard(table1.playersTableSite, "card1");
  handdeck1.playCard(table1.playersTableSite, "card2");
  handdeck1.playCard(table1.playersTableSite, "card3");
  handdeck1.playCard(table1.playersTableSite, "card4");
  handdeck1.playCard(table1.playersTableSite, "card5");
  handdeck1.playCard(table1.playersTableSite, "card6");

  ASSERT_EQ(5, table1.playersTableSite->cards->size());
  ASSERT_EQ(1, handdeck1.cards->size());
}

TEST(TransferingCardsToDiscardDeck, ItShouldtransferCardsFromTableDeckToDiscardDeck)
{
  Table table1;

  table1.playersTableSite -> addCard("card1");
  table1.playersTableSite -> addCard("card2");
  table1.playersTableSite -> addCard("card3");
  table1.playersTableSite -> addCard("card4");
  table1.playersTableSite -> addCard("card5");

  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card1");
  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card2");
  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card3");
  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card4");
  table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card5");

  ASSERT_EQ(5, table1._playersDiscardDeck.cards->size());
  ASSERT_EQ(0, table1._playersTableSite.cards->size());
}
