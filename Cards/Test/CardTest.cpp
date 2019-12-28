#include "Card.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(CardTest, ItshouldReturnString_useCard)
{
    Card card1;
	ASSERT_EQ("useCard", card1.useCard());
}