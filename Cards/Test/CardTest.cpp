#include "Card.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(CardTest, ItshouldReturnEmptyString)
{
    Card card1;
	ASSERT_EQ("", card1.useCard());
}

TEST(CardTest, ItshouldReturnString_useMonsterCard)
{
    MonsterCard card2;
	Card *cardType;
	cardType = &card2;
	ASSERT_EQ("useMonsterCard", cardType -> useCard());
}

TEST(CardTest, ItshouldReturnString_useSpellCard)
{
    SpellCard card3;
	Card *cardType;
	cardType = &card3;
	ASSERT_EQ("useSpellCard", cardType -> useCard());
}