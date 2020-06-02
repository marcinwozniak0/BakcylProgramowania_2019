#include "Game.hpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace ::testing;

TEST(clearing_Handdeck,Itshouldclearcards_in_deck)
{
  GameControler game1;
  Player pl(10);
  game1.cleanUP(pl.handdeck);
  ASSERT_EQ(pl.handdeck.size(),0);
}
