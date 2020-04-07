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

  bool isOk = true;
  if(handeck1.Cards.at(0) != "card1" && handeck1.Cards.at(0) != "card2")
  {
    isOk = false;
  }
  EXPECT_TRUE(isOk);
}

TEST(CardIsDisardedroperly, ItShouldDiscardCards)
{
  DiscardDeck discarddeck1(100);
  PullDeck pulldeck1(33);
  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  HandDeck handeck1(111);
  handeck1.drawCard(pulldeck1);
  handeck1.drawCard(pulldeck1);
  handeck1.discardCard(discarddeck1, "card1");

  ASSERT_EQ(1, pulldeck1.Cards.size()+1);
  ASSERT_EQ(1, handeck1.Cards.size());
  ASSERT_EQ(1, discarddeck1.Cards.size());
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
