#include "Table.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(PlaysCardProperly, ItShouldPlayCards)
{
  Table table1;
  Deck pulldeck1;
  HandDeck handdeck1(10);

  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  pulldeck1.addCard("card3");
  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);

 table1.*playersTableSite -> playCard(handdeck1, _playersTableSite, "card1");
 //  _playersTableSite.playCard(handdeck1, _playersTableSite, "card2")
 //  _playersTableSite.playCard(handdeck1, _playersTableSite, "card3")
 //
 //  ASSERT_EQ("card1", _playersTableSite._cards.at(2));
 //  ASSERT_EQ("card2", _playersTableSite._cards.at(1));
 //  ASSERT_EQ("card3", _playersTableSite._cards.at(0));
  //ASSERT_EQ(3, table1._playersTableSite._cards.size());
}

// TEST(LimitOfCardsOnTable, ItShouldWarnPlayerAboutTryOfPassingLimitOfCardsOnTableAndDiscardDeck)
// {
//   Table table1;
//   Deck pulldeck1;
//   HandDeck handdeck1(10);
//
//   pulldeck1.addCard("card1");
//   pulldeck1.addCard("card2");
//   pulldeck1.addCard("card3");
//   pulldeck1.addCard("card4");
//   pulldeck1.addCard("card5");
//   pulldeck1.addCard("card6");
//   handdeck1.drawCard(pulldeck1);
//   handdeck1.drawCard(pulldeck1);
//   handdeck1.drawCard(pulldeck1);
//   handdeck1.drawCard(pulldeck1);
//   handdeck1.drawCard(pulldeck1);
//   handdeck1.drawCard(pulldeck1);
//
// }
