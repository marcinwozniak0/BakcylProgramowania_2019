#include "Monster.hpp"
#include "Points.hpp"
#include <gtest/gtest.h>

using namespace ::testing;


TEST(MonsterTest, ItShouldSetStateToActive)
{
   Monster card(Points(1), Points(1), 0);
   card.activateCard();
	ASSERT_EQ(Monster::State::active, card._state);
}

TEST(MonsterTest, ItShouldReturnInt_15_numberOfYourHpPoints)
{
    Monster card4(Points(20), Points(0), 0);
    card4.dealDamage(card4._hp,5);
	ASSERT_EQ(15, card4._hp._currentPoints);
}

//TODO write more tests
