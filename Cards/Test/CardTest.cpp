#include "Card.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(CardTest, ItShouldReturnEmptyString)
{
    Card card1;
	ASSERT_EQ("", card1.useCard());
}

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

TEST(CardTest, ItShouldBeDefaultHpValue)
{
    MonsterCard card4;
	ASSERT_EQ(20, card4.hp);
}

TEST(CardTest, ItShouldBeDefaultDmgValue)
{
    MonsterCard card5;
	ASSERT_EQ(10, card5.dmg);
}

TEST(CardTest, ItShouldBeChosenDmgAndHpValue)
{
    MonsterCard card6(1,2);
	ASSERT_EQ(1, card6.hp);
	ASSERT_EQ(2, card6.dmg);
}