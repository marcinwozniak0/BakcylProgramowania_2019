#include "ProfessionRogue.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>
#include "Points.hpp"
#include "CardPool.hpp"

using namespace ::testing;

TEST(RogueUsingUltCardSteal, ItShouldReturnChangedHandDecks)
{
  std::optional<Player> player1 = Player(Points(20), Points(20), 10);
  std::optional<Player> player2 = Player(Points(20), Points(20), 10);
  CardPool cardpoolTEST;

  player1.value()._playersHanddeck.addCard(cardpoolTEST._monsterCardPool[0]);
  player1.value()._playersHanddeck.addCard(cardpoolTEST._monsterCardPool[1]);

  player2.value()._playersHanddeck.addCard(cardpoolTEST._monsterCardPool[0]);
  player2.value()._playersHanddeck.addCard(cardpoolTEST._monsterCardPool[1]);

  Rogue rg1;
  bool rng_in_range = true;
  if(rg1.rng >= player2.value()._playersHanddeck.getSize())
  {
    rng_in_range = false;
  }
	Profession *ProfType;
   ProfType = &rg1;
   ProfType -> useUlt(player1, player2);

  ASSERT_EQ(1, player2.value()._playersHanddeck.getSize());
  ASSERT_EQ(3, player1.value()._playersHanddeck.getSize());
  EXPECT_TRUE(rng_in_range);
}
