#include "Player.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(PlayerTest, positionShouldBe_x0_y0ByDefault)
{
    Position expectedPlayerPosition = Position(0, 0);
    auto player = Player(Points(20), Points(20));

    ASSERT_EQ(player.getCurrentPosition(), expectedPlayerPosition);
}

TEST(PlayerTest, testSetNewPosition)
{
    Position expectedPlayerPosition = Position(1, 1);
    auto player = Player(Points(20), Points(20));

    player.setNewPosition(Position(1, 1));

    ASSERT_EQ(player.getCurrentPosition(), expectedPlayerPosition);
}
