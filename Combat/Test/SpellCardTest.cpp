#include "SpellCard.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(SpellCardTest, ItShouldReturnString_useSpellCard)
{
    SpellCard card3;
	Card *cardType;
	cardType = &card3;
	ASSERT_EQ("useSpellCard", cardType -> useCard());
}
