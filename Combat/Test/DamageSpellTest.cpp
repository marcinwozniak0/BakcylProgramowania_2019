#include "DamageSpell.hpp"
#include "Monster.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(DamageSpellTest, ItShouldDealDamage)
{
   Monster card(Points(5), Points(1), "", "", 0);
   DamageSpell spell(4, "", "", 0);
   Points hp = card.getHp();
   spell.damage(hp);
   card.setHp(hp);
   ASSERT_EQ(1, card.getHp()._currentPoints);
}
