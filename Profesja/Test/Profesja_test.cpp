#include "Profesja.hpp"
#include <gtest/gtest.h>
#include <iostream>

using namespace ::testing;

TEST(PaladinUsingUltHeal, ItShouldReturn21)
{
  Player p1;
  Player p2;
  Paladin pl1;
	Profession *ProfType;
	ProfType = &pl1;
  ProfType -> useUlt(p1, p2);
	ASSERT_EQ(21, p1.currentHp);
}

TEST(MageUsingUltAttack, ItShouldReturn19)
{
  Player p1;
  Player p2;
  Mage mg1;
	Profession *ProfType;
	ProfType = &mg1;
  ProfType -> useUlt(p1);
	ASSERT_EQ(19, p2.currentHp);
}

TEST(RogueUsingUltCardSteal, ItShouldReturnChangedHandDecks)
{
  Player p1;
  Player p2;
  Rogue rg1;

  bool rng_in_range = true;
  if(rg1.rng >= p2.handdeck.size())
  {
    rng_in_range = false;
  }

	Profession *ProfType;
	ProfType = &rg1;
  ProfType -> useUlt(p1, p2);

  ASSERT_EQ(2, p2.handdeck.size());
  ASSERT_EQ(4, p1.handdeck.size());
  EXPECT_TRUE(rng_in_range);
}
