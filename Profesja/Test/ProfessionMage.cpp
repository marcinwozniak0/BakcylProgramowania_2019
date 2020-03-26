#include "ProfessionMage.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>

using namespace ::testing;

TEST(MageUsingUltAttack, ItShouldReturn19)
{
  std::optional<Player> p1 = Player();
  std::optional<Player> p2 = Player();
  Mage mg1;
  Profession *ProfType;
  ProfType = &mg1;
  ProfType -> useUlt(p1, p2);
  ASSERT_EQ(19, p2.value().currentHp);
}
