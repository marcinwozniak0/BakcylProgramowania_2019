#include "Table.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

// TEST(PlaysCardProperly, ItShouldPlayCards)
// {
//   Table table1;
//   HandDeck handdeck1(5);
//   handdeck1.addCard("card1");
//   handdeck1.addCard("card2");
//   handdeck1.addCard("card3");
//   handdeck1.addCard("card4");
//
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card1");
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card2");
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card3");
//
//   ASSERT_EQ("card1", table1._playersTableSite._cards.at(0));
//   ASSERT_EQ("card2", table1._playersTableSite._cards.at(1));
//   ASSERT_EQ("card3", table1._playersTableSite._cards.at(2));
//   ASSERT_EQ(3, table1._playersTableSite._cards.size());
// }
//
// TEST(LimitOfCardsOnTable, ItShouldWarnPlayerAboutTryOfPassingLimitOfCardsOnTableAndDiscardDeck)
// {
//   Table table1;
//   HandDeck handdeck1(10);
//
//   handdeck1.addCard("card1");
//   handdeck1.addCard("card2");
//   handdeck1.addCard("card3");
//   handdeck1.addCard("card4");
//   handdeck1.addCard("card5");
//   handdeck1.addCard("card6");
//
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card1");
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card2");
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card3");
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card4");
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card5");
//   table1.playersTableSite -> playCard(handdeck1, table1._playersTableSite, "card6");
//
//   ASSERT_EQ(5, table1._playersTableSite._cards.size());
//   ASSERT_EQ(1, handdeck1._cards.size());
// }

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

  ASSERT_EQ(5, table1._playersDiscardDeck._cards.size());
  ASSERT_EQ(0, table1._playersTableSite._cards.size());
}
