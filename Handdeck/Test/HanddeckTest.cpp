#include "Handdeck.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(AddingCardsToDeck, ItShouldAddCards)
{
  PullDeck pulldeck1(33);
  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  ASSERT_EQ("card1", pulldeck1.Cards.at(0));
  ASSERT_EQ("card2", pulldeck1.Cards.at(1));
}

TEST(CardIsDrawnProperly, ItShouldDrawCards)
{
  PullDeck pulldeck1(33);
  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  HandDeck handeck1(111);
  handeck1.drawCard(pulldeck1);

  bool isOk = false;
  if(handeck1.Cards.at(0) == "card1" || handeck1.Cards.at(0) == "card2")
  {
    isOk = true;
  }
  EXPECT_TRUE(isOk);
  ASSERT_EQ(1, pulldeck1.Cards.size());
}

TEST(CardIsDisardedProperly, ItShouldDiscardCards)
{
  DiscardDeck discarddeck1(100);
  PullDeck pulldeck1(33);
  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  HandDeck handeck1(111);
  handeck1.drawCard(pulldeck1);
  handeck1.drawCard(pulldeck1);
  TableDeck tabledeck1(10);
  handeck1.playCard(tabledeck1, "card1");
  handeck1.playCard(tabledeck1, "card2");
  tabledeck1.discardCard(discarddeck1, "card1");
  tabledeck1.discardCard(discarddeck1, "card2");

  ASSERT_EQ(0, pulldeck1.Cards.size());
  ASSERT_EQ(0, handeck1.Cards.size());
  ASSERT_EQ(0, tabledeck1.Cards.size());
  ASSERT_EQ(2, discarddeck1.Cards.size());
}

TEST(CardIsPlayedProperly, ItShouldPlayCards)
{
  PullDeck pulldeck1(33);
  pulldeck1.addCard("card1");
  HandDeck handeck1(111);
  TableDeck tabledeck1(10);
  handeck1.drawCard(pulldeck1);
  handeck1.playCard(tabledeck1, "card1");

  ASSERT_EQ(0, pulldeck1.Cards.size());
  ASSERT_EQ("card1", tabledeck1.Cards.at(0));
}
