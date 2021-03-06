#include "LimitedDeck.hpp"
#include "Table.hpp"
#include "CardPool.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

static CardPool cardpoolTEST;

//Test will be using copied Card examples from basic Card Pool
//and '==' Card operator

TEST(AddingCardsToDeck, ItShouldAddCards)
{
  Deck pulldeck1;

  pulldeck1.addCard(cardpoolTEST._monsterCardPool[0]);
  pulldeck1.addCard(cardpoolTEST._SpellCardPool[0]);

  ASSERT_EQ(cardpoolTEST._monsterCardPool[0], pulldeck1.cards->at(0));
  ASSERT_EQ(cardpoolTEST._SpellCardPool[0], pulldeck1.cards->at(1));
  ASSERT_EQ(2, pulldeck1.cards->size());
}

TEST(SchuffleingCards, ItShouldSchuffleCards)
{
  Deck pulldeck1;

  pulldeck1.addCard(cardpoolTEST._monsterCardPool[0]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[1]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[2]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[3]);
  pulldeck1.addCard(cardpoolTEST._SpellCardPool[0]);
  pulldeck1.addCard(cardpoolTEST._SpellCardPool[1]);
  pulldeck1.addCard(cardpoolTEST._SpellCardPool[2]);
  pulldeck1.addCard(cardpoolTEST._SpellCardPool[3]);

  Deck pulldeck2;

  pulldeck2.addCard(cardpoolTEST._monsterCardPool[0]);
  pulldeck2.addCard(cardpoolTEST._monsterCardPool[1]);
  pulldeck2.addCard(cardpoolTEST._monsterCardPool[2]);
  pulldeck2.addCard(cardpoolTEST._monsterCardPool[3]);
  pulldeck2.addCard(cardpoolTEST._SpellCardPool[0]);
  pulldeck2.addCard(cardpoolTEST._SpellCardPool[1]);
  pulldeck2.addCard(cardpoolTEST._SpellCardPool[2]);
  pulldeck2.addCard(cardpoolTEST._SpellCardPool[3]);

  pulldeck1.shuffleCards();

  ASSERT_NE(*pulldeck1.cards, *pulldeck2.cards);
  ASSERT_EQ(8, pulldeck1.cards->size());
  ASSERT_EQ(8, pulldeck2.cards->size());
}

TEST(DrawCardsProperly, ItShouldDrawCards)
{
  Deck pulldeck1;
  HandDeck handdeck1(11);

  pulldeck1.addCard(cardpoolTEST._monsterCardPool[0]);
  pulldeck1.addCard(cardpoolTEST._SpellCardPool[0]);

  handdeck1.drawCard(pulldeck1);

  ASSERT_EQ(cardpoolTEST._SpellCardPool[0], pulldeck1.cards->at(0));
  ASSERT_EQ(cardpoolTEST._monsterCardPool[0], handdeck1.cards->at(0));
  ASSERT_EQ(1, handdeck1.cards->size());
  ASSERT_EQ(1, pulldeck1.cards->size());
}

TEST(DrawCardsMaxSize, ItShouldDrawCards)
{
  Deck pulldeck1;
  HandDeck handdeck1(2);

  pulldeck1.addCard(cardpoolTEST._monsterCardPool[0]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[1]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[2]);

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

  pulldeck1.addCard(cardpoolTEST._monsterCardPool[0]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[1]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[2]);
  handdeck1.drawCard(pulldeck1);
  handdeck1.drawCard(pulldeck1);
  handdeck1.moveCard(discarddeck1, cardpoolTEST._monsterCardPool[0]);

  ASSERT_EQ(cardpoolTEST._monsterCardPool[1], handdeck1.cards->at(0));
  ASSERT_EQ(cardpoolTEST._monsterCardPool[0], discarddeck1.cards->at(0));
  ASSERT_EQ(cardpoolTEST._monsterCardPool[2], pulldeck1.cards->at(0));
  ASSERT_EQ(1, handdeck1.cards->size());
  ASSERT_EQ(1, pulldeck1.cards->size());
  ASSERT_EQ(1, discarddeck1.cards->size());
}

TEST(FindsCardsProperly, ItFindsTheRighCard)
{
  Deck pulldeck1;
  Card card1 = cardpoolTEST._monsterCardPool[0];
  Card card2 = cardpoolTEST._monsterCardPool[1];
  Card card3 = cardpoolTEST._monsterCardPool[2];
  pulldeck1.addCard(card1);
  pulldeck1.addCard(card2);
  pulldeck1.addCard(card3);
  uint cardIndex1 = pulldeck1.findCard(card1);
  uint cardIndex2 = pulldeck1.findCard(card3);

  ASSERT_EQ(0, cardIndex1);
  ASSERT_EQ(2, cardIndex2);
}

TEST(ExpectThrowingException, ItShouldThrowException)
{
  Deck pulldeck1;
  Card testcard = cardpoolTEST._monsterCardPool[8];

  pulldeck1.addCard(cardpoolTEST._monsterCardPool[0]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[1]);
  pulldeck1.addCard(cardpoolTEST._monsterCardPool[2]);

  EXPECT_THROW(pulldeck1.findCard(testcard), std::out_of_range);
}


TEST(PlaysCardProperly, ItShouldPlayCards)
{
  Table table1;
  HandDeck handdeck1(5);

  handdeck1.addCard(cardpoolTEST._monsterCardPool[0]);
  handdeck1.addCard(cardpoolTEST._monsterCardPool[1]);
  handdeck1.addCard(cardpoolTEST._monsterCardPool[2]);
  handdeck1.addCard(cardpoolTEST._monsterCardPool[3]);

  handdeck1.playCard(table1.playersTableSite, handdeck1.cards->at(0));
  handdeck1.playCard(table1.playersTableSite, handdeck1.cards->at(2));

  ASSERT_EQ(cardpoolTEST._monsterCardPool[0], table1.playersTableSite->cards->at(0));
  ASSERT_EQ(cardpoolTEST._monsterCardPool[3], table1.playersTableSite->cards->at(1));
  ASSERT_EQ(2, table1.playersTableSite->cards->size());
  ASSERT_EQ(2, handdeck1.cards->size());
}
