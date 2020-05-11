#include "LimitedDeck.hpp"
#include "../../Table/Include/Table.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(AddingCardsToDeck, ItShouldAddCards)
{
  Deck pulldeck1;

  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");

  ASSERT_EQ("card1", pulldeck1.cards->at(0));
  ASSERT_EQ("card2", pulldeck1.cards->at(1));
  ASSERT_EQ(2, pulldeck1.cards->size());
}

TEST(SchuffleingCards, ItShouldSchuffleCards)
{
  Deck pulldeck1;

  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  pulldeck1.addCard("card3");
  pulldeck1.addCard("card4");
  pulldeck1.addCard("card5");
  pulldeck1.addCard("card6");
  pulldeck1.addCard("card7");
  pulldeck1.addCard("card8");

  Deck pulldeck2;

  pulldeck2.addCard("card1");
  pulldeck2.addCard("card2");
  pulldeck2.addCard("card3");
  pulldeck2.addCard("card4");
  pulldeck2.addCard("card5");
  pulldeck2.addCard("card6");
  pulldeck2.addCard("card7");
  pulldeck2.addCard("card8");

  pulldeck1.shuffleCards();

  ASSERT_NE(*pulldeck1.cards, *pulldeck2.cards);
  ASSERT_EQ(8, pulldeck1.cards->size());
  ASSERT_EQ(8, pulldeck2.cards->size());
}

TEST(DrawCardsProperly, ItShouldDrawCards)
{
  Deck pulldeck1;
  HandDeck handdeck1(11);

  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");

  handdeck1.drawCard(pulldeck1);

  ASSERT_EQ("card1", handdeck1.cards->at(0));
  ASSERT_EQ(1, handdeck1.cards->size());
  ASSERT_EQ(1, pulldeck1.cards->size());
}

TEST(DrawCardsMaxSize, ItShouldDrawCards)
{
  Deck pulldeck1;
  HandDeck handdeck1(2);

  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  pulldeck1.addCard("card3");

  pulldeck1.shuffleCards();

  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);

  ASSERT_EQ(2, handdeck1.cards->size());
  ASSERT_EQ(1, pulldeck1.cards->size());
}

TEST(MoveCardsProperly, ItShouldMoveCards)
{
  Deck pulldeck1;
  Deck discarddeck1;
  HandDeck handdeck1(11);

  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  pulldeck1.addCard("card3");
  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);
  handdeck1.moveCard(discarddeck1, "card1");

  ASSERT_EQ("card2", handdeck1.cards->at(0));
  ASSERT_EQ("card1", discarddeck1.cards->at(0));
  ASSERT_EQ("card3", pulldeck1.cards->at(0));
  ASSERT_EQ(1, handdeck1.cards->size());
  ASSERT_EQ(1, pulldeck1.cards->size());
  ASSERT_EQ(1, discarddeck1.cards->size());
}

TEST(FindsCardsProperly, ItFindsTheRighCard)
{
  Deck pulldeck1;
  Card card1 = {"card1"};
  Card card3 = {"card3"};
  pulldeck1.addCard(card1);
  pulldeck1.addCard("card2");
  pulldeck1.addCard(card3);
  uint cardIndex1 = pulldeck1.findCard(card1);
  uint cardIndex2 = pulldeck1.findCard(card3);

  ASSERT_EQ(0, cardIndex1);
  ASSERT_EQ(2, cardIndex2);
}

TEST(ExpectThrowingException, ItShouldThrowException)
{
  Deck pulldeck1;
  Card testcard = {"card6"};

  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  pulldeck1.addCard("card3");

  EXPECT_THROW(pulldeck1.findCard(testcard), std::runtime_error);
}


TEST(PlaysCardProperly, ItShouldPlayCards)
{
  Table table1;
  HandDeck handdeck1(5);

  handdeck1.addCard("card1");
  handdeck1.addCard("card2");
  handdeck1.addCard("card3");
  handdeck1.addCard("card4");

  handdeck1.playCard(table1.playersTableSite, "card1");
  handdeck1.playCard(table1.playersTableSite, "card4");

  ASSERT_EQ("card1", table1.playersTableSite->cards->at(0));
  ASSERT_EQ("card4", table1.playersTableSite->cards->at(1));
  ASSERT_EQ(2, table1.playersTableSite->cards->size());
  ASSERT_EQ(2, handdeck1.cards->size());
}
