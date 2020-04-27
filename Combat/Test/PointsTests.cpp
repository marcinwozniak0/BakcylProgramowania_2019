#include "Points.hpp"
#include <iostream>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(PointsTest, Constructor_AssignsValues)
{
    Points p(100);
    ASSERT_EQ(p.getMaxPoints(), 100);
    ASSERT_EQ(p.getCurrentPoints(), 100);
    p = Points(200, 10);
    ASSERT_EQ(p.getMaxPoints(), 200);
    ASSERT_EQ(p.getCurrentPoints(), 10);
}

TEST(PointsTest, Constructor_DoesNotAllowCurrentpointsGreaterThanMaxpoints)
{
    Points p(10, 15);
    ASSERT_EQ(p.getCurrentPoints(), 10);
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

TEST(PointsTest, AddOperator_AddsCurrentpoints)
{
    Points p1(100, 20);
    Points p2(100, 30);
    auto result = p1 + p2;
    ASSERT_EQ(result.getCurrentPoints(), 50);
}

TEST(PointsTest, SubtractOperator_SubtractsCurrentpoints)
{
   Points p1(150, 100);
   Points p2(60, 40);
   auto result = p1 - p2;
   ASSERT_EQ(result.getCurrentPoints(), 60);
}

TEST(PointsTest, SubtractOperator_SetsCurrentpointsToZeroWhenNeeded)
{
   Points p1(100, 10);
   Points p2(50, 40);
   auto result = p1 - p2;
   ASSERT_EQ(result.getCurrentPoints(), 0);
}

TEST(PointsTest, GreaterThanOperator_ReturnsTrueWhenCurrentPointsAreGreater)
{
   Points p1(100);
   Points p2(200);
   ASSERT_TRUE(p2 > p1);
}

TEST(PointsTest, GreaterThanOperator_ReturnsFalseWhenCurrentPointsAreLower)
{
   Points p1(100);
   Points p2(50);
   ASSERT_FALSE(p2 > p1);
}

TEST(PointsTest, LowerThanOperator_ReturnsTrueWhenCurrentPointsAreLower)
{
   Points p1(100);
   Points p2(50);
   ASSERT_TRUE(p2 < p1);
}

TEST(PointsTest, LowerThanOperator_ReturnsFalseWhenCurrentPointsAreGreater)
{
   Points p1(100);
   Points p2(200);
   ASSERT_FALSE(p2 < p1);
}

TEST(PointsTest, GreaterThanOrEqualOperator_ReturnsTrueWhenCurrentPointsAreGreater)
{
   Points p1(100);
   Points p2(200);
   ASSERT_TRUE(p2 >= p1);
}

TEST(PointsTest, GreaterThanOrEqualOperator_ReturnsTrueWhenCurrentPointsAreEqual)
{
   Points p1(100);
   Points p2(100);
   ASSERT_TRUE(p2 >= p1);
}

TEST(PointsTest, GreaterThanOrEqualOperator_ReturnsFalseWhenCurrentPointsAreSmaller)
{
   Points p1(200);
   Points p2(100);
   ASSERT_FALSE(p2 >= p1);
}

TEST(PointsTest, SmallerThanOrEqualOperator_ReturnsTrueWhenCurrentPointsAreSmaller)
{
   Points p1(200);
   Points p2(100);
   ASSERT_TRUE(p2 <= p1);
}

TEST(PointsTest, SmallerThanOrEqualOperator_ReturnsTrueWhenCurrentPointsAreEqual)
{
   Points p1(100);
   Points p2(100);
   ASSERT_TRUE(p2 <= p1);
}

TEST(PointsTest, SmallerThanOrEqualOperator_ReturnsFalseWhenCurrentPointsAreGreater)
{
   Points p1(100);
   Points p2(200);
   ASSERT_FALSE(p2 <= p1);
}

//Method
TEST(PointsTest, AddMethod_AddsCurrentPoints)
{
  Points p1(100, 40);
  p1.add(50);
  ASSERT_EQ(p1.getCurrentPoints(), 90);
}

TEST(PointsTest, AddMethod_DoesNotAllowCurrentPointsGreaterThanMaxPoints)
{
  Points p1(100, 60);
  p1.add(50);
  ASSERT_EQ(p1.getCurrentPoints(), 100);
}

TEST(PointsTest, RemoveMethod_RemovesCurrentPoints)
{
  Points p1(100, 70);
  p1.remove(50);
  ASSERT_EQ(p1.getCurrentPoints(), 20);
}

TEST(PointsTest, RemoveMethod_DoesNotAllowCurrentPointsLowerThan0)
{
  Points p1(100, 30);
  p1.remove(50);
  ASSERT_EQ(p1.getCurrentPoints(), 0);
}

TEST(PointsTest, ResetCurrent_ResetsCurrentPoints)
{
   Points p1(100);
   p1.remove(50);
   p1.resetCurrent();
   ASSERT_EQ(p1.getCurrentPoints(), 100);
}

TEST(PointsTest, SetMaxTo_AllighnsMaxPointsToValue)
{
  Points p1(100);
  p1.setMaxTo(150);
  ASSERT_EQ(p1.getMaxPoints(), 150);
}

TEST(PointsTest, getCurrentPoints_ReturnsCurrentPoints)
{
   Points p1(100);
   ASSERT_EQ(p1.getCurrentPoints(), 100);
}

TEST(PointsTest, setCurrentPoints_SetsCurrentPointsValue)
{
  Points p1(100);
  p1.setCurrentPoints(20);
  ASSERT_EQ(p1.getCurrentPoints(), 20);
}
