#include "ProfessionPaladin.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>
#include "Points.hpp"

using namespace ::testing;

TEST(PaladinUsingUltHeal, ItShouldReturn20)
{
  std::optional<Player> player1 = Player(Points(21,19), Points(20), 10);
  std::optional<Player> player2 = Player(Points(21,19), Points(20), 10);
  Paladin pl1;
  Profession *ProfType;
  ProfType = &pl1;
  ProfType -> useUlt(player1, player2);
  ASSERT_EQ(20, player1.value()._HP.getCurrentPoints());
}
