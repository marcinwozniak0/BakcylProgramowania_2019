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

TEST(CardTest, ItShouldReturnString_someDamageTaken)
{
    MonsterCard card4;
	ASSERT_EQ("someDamageTaken", card4.takeDamage());
}