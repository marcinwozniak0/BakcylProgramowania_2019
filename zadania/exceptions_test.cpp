#include <gtest/gtest.h>
#include "exceptions.hpp"

TEST(ExceptionsTest, foo)
{
    constexpr auto position = 5u;
    ASSERT_TRUE(firstTask(position));
}
