#include "Points.hpp"
#include <iostream>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(PointsTest, Constructor_AssignsValues)
{
    Points p(100);
    ASSERT_EQ(p._maxPoints, 100);
    ASSERT_EQ(p._currentPoints, 100);

    p = Points(200, 10);
    ASSERT_EQ(p._maxPoints, 200);
    ASSERT_EQ(p._currentPoints, 10);
}

TEST(PointsTest, Constructor_DoesNotAllowCurrentpointsGreaterThanMaxpoints)
{
    Points p(10, 15);
    ASSERT_EQ(p._currentPoints, 10);
}

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

TEST(PointsTest, AdddOperator_AddsCurrentpoints)
{
    Points p1(100, 20);
    Points p2(100, 30);

    auto result = p1 + p2;
    ASSERT_EQ(result._currentPoints, 50);
}

TEST(PointsTest, AdddOperator_AddsMaxpoints)
{
    Points p1(100, 20);
    Points p2(100, 30);

    auto result = p1 + p2;
    ASSERT_EQ(result._maxPoints, 200);
}

TEST(PointsTest, AdddOperator_AddsBoth)
{
    Points p1(100, 50);
    Points p2(60, 30);

    auto result = p1 + p2;
    ASSERT_EQ(result._maxPoints, 160);
    ASSERT_EQ(result._currentPoints, 80);
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
   Points p1(150, 100);
   Points p2(60, 40);

   auto result = p1 - p2;
   ASSERT_EQ(result._currentPoints, 60);
}

TEST(PointsTest, SubtractOperator_SubtractsBoth)
{
    Points p1(300, 100);
    Points p2(200, 50);

    auto result = p1 - p2;
    ASSERT_EQ(result._maxPoints, 100);
    ASSERT_EQ(result._currentPoints, 50);
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
