#include "Game.hpp"
#include "SquareMap.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

namespace
{
    constexpr auto mapSize = 8u;
    SquareMap map(mapSize);
}

class GameTest : public Test
{
protected:
    GameTest() : game(map) {}
    Game game;
};

TEST_F(GameTest, isBuildingWell)
{
    ASSERT_TRUE(true);
}