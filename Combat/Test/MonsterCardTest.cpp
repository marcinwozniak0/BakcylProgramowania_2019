#include "MonsterCard.hpp"
#include <gtest/gtest.h>

using namespace ::testing;


TEST(MonsterCardTest, ItShouldReturnString_useMonsterCard)
{
    MonsterCard card2;
	Card *cardType;
	cardType = &card2;
	ASSERT_EQ("useMonsterCard", cardType -> useCard());
}

TEST(MonsterCardTest, ItShouldReturnInt_15_numberOfYourHpPoints)
{
    MonsterCard card4;
	ASSERT_EQ(15, card4.takeDamage(5));
}

TEST(MonsterCardTest, ItShouldReturnInt_10_numberOfYourHpPoints)
{
    MonsterCard card5(25,10);
	ASSERT_EQ(10, card5.takeDamage(15));
}
