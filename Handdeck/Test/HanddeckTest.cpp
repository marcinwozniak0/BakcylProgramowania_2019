#include "Handdeck.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(AddingCardsToDeck, ItShouldAddCards)
{
  PullDeck pulldeck1(33);
  pulldeck1.addCard("card1");
  ASSERT_EQ("card1", pulldeck1.Cards.at(0));
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
  DiscardDeck tableDeck1(33);
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
