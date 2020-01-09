#include "Card.hpp"
#include <gtest/gtest.h>

using namespace ::testing;


TEST(CardTest, ItShouldReturnString_useMonsterCard)
{
    MonsterCard card2;
	Card *cardType;
	cardType = &card2;
	ASSERT_EQ("useMonsterCard", cardType -> useCard());
}

TEST(CardTest, ItShouldReturnString_useSpellCard)
{
    SpellCard card3;
	Card *cardType;
	cardType = &card3;
	ASSERT_EQ("useSpellCard", cardType -> useCard());
}

TEST(CardTest, ItShouldReturnInt_15_numberOfYourHpPoints)
{
    MonsterCard card4;
	ASSERT_EQ(15, card4.takeDamage(5));
}

TEST(CardTest, ItShouldReturnInt_10_numberOfYourHpPoints)
{
    MonsterCard card5(25,10);
	ASSERT_EQ(10, card5.takeDamage(15));
}