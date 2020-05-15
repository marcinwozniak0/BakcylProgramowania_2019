#include "ProfessionMage.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>
#include "Points.hpp"

using namespace ::testing;

TEST(MageUsingUltAttack, ItShouldReturn19)
{
  std::optional<Player> player1 = Player(Points(20), Points(20));
  std::optional<Player> player2 = Player(Points(20), Points(20));
  Mage mg1;
  Profession *ProfType;
  ProfType = &mg1;
  ProfType -> useUlt(player1, player2);
  ASSERT_EQ(19, player2.value()._hp.getCurrentPoints());
}
