#include "ProfessionPaladin.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>

using namespace ::testing;

TEST(PaladinUsingUltHeal, ItShouldReturn21)
{
  std::optional<Player> player1 = Player(20);
  std::optional<Player> player2 = Player(20);
  Paladin pl1;
  Profession *ProfType;
  ProfType = &pl1;
  ProfType -> useUlt(player1, player2);
  ASSERT_EQ(21, player1.value().currentHp);
}
