#include "Points.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(PointsTest, EqualOperator_ReturnsTrueWhenAreTheSame)
{
    Points p1(100);
    Points p2(100);

    ASSERT_TRUE(p1 == p2);
}


TEST(PointsTest, EqualOperator_ReturnsFalseWhenAreNotTheSame)
{
    Points p1(100);
    Points p2(1);

    ASSERT_FALSE(p1 == p2);
}