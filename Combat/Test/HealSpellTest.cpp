#include "HealSpell.hpp"
#include "Monster.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(HealSpellTest, ItShouldHeal)
{
   Monster card(Points(5,1), Points(1), "", "", 0);
   HealSpell spell(4, "", "", 0);
   Points hp = card.getHp();
   spell.heal(hp);
   card.setHp(hp);
   ASSERT_EQ(5, card.getHp()._currentPoints);
}
