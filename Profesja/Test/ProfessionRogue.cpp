#include "ProfessionRogue.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>

using namespace ::testing;

TEST(RogueUsingUltCardSteal, ItShouldReturnChangedHandDecks)
{
  std::optional<Player> player1 = Player(20);
  std::optional<Player> player2 = Player(20);
  Rogue rg1;

  bool rng_in_range = true;
  if(rg1.rng >= player2.value().handdeck.size())
  {
    rng_in_range = false;
  }

	Profession *ProfType;
   ProfType = &rg1;
   ProfType -> useUlt(player1, player2);

  ASSERT_EQ(2, player2.value().handdeck.size());
  ASSERT_EQ(4, player1.value().handdeck.size());
  EXPECT_TRUE(rng_in_range);
}
