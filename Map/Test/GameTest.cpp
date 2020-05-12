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

TEST_F(GameTest, getDirectionShouldReturnUp)
{
    ASSERT_EQ(Direction::Up, game.getDirection());
}

TEST_F(GameTest, getDirectionShouldReturnDown)
{
    ASSERT_EQ(Direction::Down, game.getDirection());
}

TEST_F(GameTest, getDirectionShouldReturnLeft)
{
    ASSERT_EQ(Direction::Left, game.getDirection());
}

TEST_F(GameTest, getDirectionShouldReturnRight)
{
    ASSERT_EQ(Direction::Right, game.getDirection());
}

TEST_F(GameTest, getDirectionForUppercaseShouldReturnUp)
{
    ASSERT_EQ(Direction::Up, game.getDirection());
}

TEST_F(GameTest, getDirectionForUppercaseShouldReturnDown)
{
    ASSERT_EQ(Direction::Down, game.getDirection());
}

TEST_F(GameTest, getDirectionForUppercaseShouldReturnLeft)
{
    ASSERT_EQ(Direction::Left, game.getDirection());
}

TEST_F(GameTest, getDirectionForUppercaseShouldReturnRight)
{
    ASSERT_EQ(Direction::Right, game.getDirection());
}