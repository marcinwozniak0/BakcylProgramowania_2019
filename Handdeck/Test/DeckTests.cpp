#include "Handdeck.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(AddingCardsToDeck, ItShouldAddCards)
{
  Deck pulldeck1;

  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  ASSERT_EQ("card1", pulldeck1._cards.at(0));
  ASSERT_EQ("card2", pulldeck1._cards.at(1));
  ASSERT_EQ(2, pulldeck1._cards.size());
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


  ASSERT_NE(pulldeck1._cards, pulldeck2._cards);
  ASSERT_EQ(8, pulldeck1._cards.size());
  ASSERT_EQ(8, pulldeck2._cards.size());
}

TEST(DrawCardsProperly, ItShouldDrawCards)
{
  Deck pulldeck1;
  HandDeck handdeck1(11);
  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");

  handdeck1.drawCard(pulldeck1);

  ASSERT_EQ("card1", handdeck1._cards.at(0));
  ASSERT_EQ(1, handdeck1._cards.size());
  ASSERT_EQ(1, pulldeck1._cards.size());
}

TEST(DrawCardsMaxSize, ItShouldDrawCards)
{
  Deck pulldeck1;
  HandDeck handdeck1(2);
  pulldeck1.addCard("card1");
  pulldeck1.addCard("card2");
  pulldeck1.addCard("card3");
  pulldeck1.addCard("card4");
  pulldeck1.shuffleCards();
  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);

  ASSERT_EQ(2, handdeck1._cards.size());
  ASSERT_EQ(2, pulldeck1._cards.size());
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

  ASSERT_EQ("card2", handdeck1._cards.at(0));
  ASSERT_EQ("card1", discarddeck1._cards.at(0));
  ASSERT_EQ("card3", pulldeck1._cards.at(0));
  ASSERT_EQ(1, handdeck1._cards.size());
  ASSERT_EQ(1, pulldeck1._cards.size());
  ASSERT_EQ(1, discarddeck1._cards.size());
}
