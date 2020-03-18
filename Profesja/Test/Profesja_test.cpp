#include "Profesja.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(PaladinUsingUltHeal, ItShouldReturn21)
{
  Player p1;
  Player p2;
  Player :: Paladin pl1;
	Player :: Profession *ProfType;
	ProfType = &pl1;
  ProfType -> useUlt(p1, p2);
	ASSERT_EQ(21, p1.currentHp);
}

TEST(MageUsingUltAttack, ItShouldReturn19)
{
  Player p1;
  Player p2;
  Player :: Mage mg1;
	Player :: Profession *ProfType;
	ProfType = &mg1;
  ProfType -> useUlt(p1, p2);
	ASSERT_EQ(19, p2.currentHp);
}

TEST(RogueUsingUltCardSteal, ItShouldReturnChangedHandDecks)
{
  Player p1;
  Player p2;
  Player :: Rogue rg1;
	Player :: Profession *ProfType;
	ProfType = &rg1;
  ProfType -> useUlt(p1, p2);
  ASSERT_EQ(2, p2.handdeck.size());
  ASSERT_EQ(4, p1.handdeck.size());
  ASSERT_EQ(1 || 2 || 3, rng;
}
