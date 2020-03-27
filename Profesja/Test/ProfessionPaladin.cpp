#include "ProfessionPaladin.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>

using namespace ::testing;

TEST(PaladinUsingUltHeal, ItShouldReturn21)
{
  std::optional<Player> p1 = Player(20);
  std::optional<Player> p2 = Player(20);
  Paladin pl1;
  Profession *ProfType;
  ProfType = &pl1;
  ProfType -> useUlt(p1, p2);
  ASSERT_EQ(21, p1.value().currentHp);
}
