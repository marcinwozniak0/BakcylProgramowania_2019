#include "ProfessionRogue.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>

using namespace ::testing;

TEST(RogueUsingUltCardSteal, ItShouldReturnChangedHandDecks)
{
  std::optional<Player> p1 = Player();
  std::optional<Player> p2 = Player();
  Rogue rg1;

  bool rng_in_range = true;
  if(rg1.rng >= p2.value().handdeck.size())
  {
    rng_in_range = false;
  }

	Profession *ProfType;
   ProfType = &rg1;
   ProfType -> useUlt(p1, p2);

  ASSERT_EQ(2, p2.value().handdeck.size());
  ASSERT_EQ(4, p1.value().handdeck.size());
  EXPECT_TRUE(rng_in_range);
}
