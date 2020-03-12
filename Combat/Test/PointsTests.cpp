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

TEST(PointsTest, NotEqualOperator_ReturnsTrueWhenAreNotTheSame)
{
    Points p1(100);
    Points p2(1);

    ASSERT_TRUE(p1 != p2);
}


TEST(PointsTest, NotEqualOperator_ReturnsFalseWhenAreTheSame)
{
    Points p1(100);
    Points p2(100);

    ASSERT_FALSE(p1 != p2);
}

TEST(PointsTest, SubtractOperator_SubtractsMaxpoints)
{
   Points p1(100);
   Points p2(50);

   auto result = p1 - p2;
   ASSERT_EQ(result._maxPoints, 50);
}

TEST(PointsTest, SubtractOperator_SubtractsCurrentpoints)
{
   Points p1(100, 100);
   Points p2(50, 40);

   auto result = p1 - p2;
   ASSERT_EQ(result._currentPoints, 60);
}

TEST(PointsTest, SubtractOperator_SetsCurrentpointsToZeroWhenNeeded)
{
   Points p1(100, 10);
   Points p2(50, 40);

   auto result = p1 - p2;
   ASSERT_EQ(result._currentPoints, 0);
}

TEST(PointsTest, SubtractOperator_SetsMaxpointsToZeroWhenNeeded)
{
   Points p1(10);
   Points p2(50);

   auto result = p1 - p2;
   ASSERT_EQ(result._maxPoints, 0);
}
