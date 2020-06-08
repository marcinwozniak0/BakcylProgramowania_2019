#include "Game.hpp"
#include "SquareMap.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

namespace
{
    constexpr auto mapSize = 8u;
    constexpr auto hp = 8u;
    constexpr auto mp = 8u;
    SquareMap map(mapSize);
    Player player(hp, mp);
}

class GameTest : public Test
{
protected:
    GameTest() : game(map, player) {}
    Game game;
};

TEST_F(GameTest, isBuildingWell)
{
    ASSERT_TRUE(true);
}

/*
TEST_F(GameTest, getDirectionShouldReturnUp)
{
    std::istringstream stream("w");
    std::cin.rdbuf(stream.rdbuf());
    ASSERT_EQ(Direction::Up, game.getDirection());
}

TEST_F(GameTest, getDirectionShouldReturnDown)
{
    std::istringstream stream("s");
    std::cin.rdbuf(stream.rdbuf());
    ASSERT_EQ(Direction::Down, game.getDirection());
}

TEST_F(GameTest, getDirectionShouldReturnLeft)
{
    std::istringstream stream("a");
    std::cin.rdbuf(stream.rdbuf());
    ASSERT_EQ(Direction::Left, game.getDirection());
}

TEST_F(GameTest, getDirectionShouldReturnRight)
{
    std::istringstream stream("d");
    std::cin.rdbuf(stream.rdbuf());
    ASSERT_EQ(Direction::Right, game.getDirection());
}

TEST_F(GameTest, getDirectionForUppercaseShouldReturnUp)
{
    std::istringstream stream("W");
    std::cin.rdbuf(stream.rdbuf());
    ASSERT_EQ(Direction::Up, game.getDirection());
}

TEST_F(GameTest, getDirectionForUppercaseShouldReturnDown)
{
    std::istringstream stream("S");
    std::cin.rdbuf(stream.rdbuf());
    ASSERT_EQ(Direction::Down, game.getDirection());
}

TEST_F(GameTest, getDirectionForUppercaseShouldReturnLeft)
{
    std::istringstream stream("A");
    std::cin.rdbuf(stream.rdbuf());
    ASSERT_EQ(Direction::Left, game.getDirection());
}

TEST_F(GameTest, getDirectionForUppercaseShouldReturnRight)
{
    std::istringstream stream("D");
    std::cin.rdbuf(stream.rdbuf());
    ASSERT_EQ(Direction::Right, game.getDirection());
}
*/