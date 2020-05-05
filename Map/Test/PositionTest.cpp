#include "Position.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(PositionTest, testEqualityOperator)
{
    Position lhs = Position(1, 1);
    Position rhs = Position(1, 1);

    ASSERT_EQ(lhs, rhs);
}
