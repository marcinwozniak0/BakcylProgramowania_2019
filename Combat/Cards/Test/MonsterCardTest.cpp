#include "Monster.hpp"
#include "Points.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(MonsterTest, ItShouldSetStateToActive)
{
   Monster card(Points(1), Points(1), "", 0, "", 0);
   card.activateCard();
	ASSERT_EQ(State::active, card.getState());
}

TEST(MonsterTest, ItShouldReturnHp)
{
   Monster card(Points(1), Points(1), "", 0, "", 0);
	ASSERT_EQ(1, card.getHp().getCurrentPoints());
}

TEST(MonsterTest, ItShouldSetHp)
{
   Monster card(Points(1), Points(1), "", 0, "", 0);
   card.setHp(Points(2));
	ASSERT_EQ(2, card.getHp().getCurrentPoints());
}

TEST(MonsterTest, ItShouldReturnStrength)
{
   Monster card(Points(1), Points(1), "", 0, "", 0);
	ASSERT_EQ(1, card.getStrength().getCurrentPoints());
}

TEST(MonsterTest, ItShouldSetStrength)
{
   Monster card(Points(1), Points(1), "", 0, "", 0);
   card.setStrength(Points(7));
	ASSERT_EQ(7, card.getStrength().getCurrentPoints());
}
