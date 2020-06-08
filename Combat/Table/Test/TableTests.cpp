#include "Table.hpp"
#include <gtest/gtest.h>
#include "CardPool.hpp"

using namespace ::testing;

static CardPool cardpoolTEST;

// TEST(LimitOfCardsOnTable, ItShouldWarnPlayerAboutTryOfPassingLimitOfCardsOnTableAndDiscardDeck)
// {
//   Table table1;
//   HandDeck handdeck1(10);
//   Deck pulldeck1;
//
//   pulldeck1.addCard(cardpoolTEST._monsterCardPool[0]);
//   pulldeck1.addCard(cardpoolTEST._monsterCardPool[1]);
//   pulldeck1.addCard(cardpoolTEST._monsterCardPool[2]);
//   pulldeck1.addCard(cardpoolTEST._monsterCardPool[3]);
//   pulldeck1.addCard(cardpoolTEST._monsterCardPool[4]);
//   pulldeck1.addCard(cardpoolTEST._monsterCardPool[5]);
//   std::cout<<"log1"<<std::endl;
//   handdeck1.playCard(table1.playersTableSite, pulldeck1.cards->at(0));
//   std::cout<<"log2"<<std::endl;
//   handdeck1.playCard(table1.playersTableSite, pulldeck1.cards->at(1));
//   handdeck1.playCard(table1.playersTableSite, pulldeck1.cards->at(2));
//   handdeck1.playCard(table1.playersTableSite, pulldeck1.cards->at(3));
//   handdeck1.playCard(table1.playersTableSite, pulldeck1.cards->at(4));
//   handdeck1.playCard(table1.playersTableSite, pulldeck1.cards->at(5));
//
//   ASSERT_EQ(5, table1.playersTableSite->cards->size());
//   ASSERT_EQ(1, handdeck1.cards->size());
// }

// TEST(TransferingCardsToDiscardDeck, ItShouldtransferCardsFromTableDeckToDiscardDeck)
// {
//   Table table1;
//
//   table1.playersTableSite -> addCard("card1");
//   table1.playersTableSite -> addCard("card2");
//   table1.playersTableSite -> addCard("card3");
//   table1.playersTableSite -> addCard("card4");
//   table1.playersTableSite -> addCard("card5");
//
//   table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card1");
//   table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card2");
//   table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card3");
//   table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card4");
//   table1.playersTableSite -> moveCard(table1._playersDiscardDeck, "card5");
//
//   ASSERT_EQ(5, table1._playersDiscardDeck.cards->size());
//   ASSERT_EQ(0, table1._playersTableSite.cards->size());
// }
