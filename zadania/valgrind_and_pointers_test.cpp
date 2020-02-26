#include <gtest/gtest.h>
#include "valgrind_and_pointers.hpp"

TEST(ValgrindTest, foo)
{
    constexpr auto position = 5u;
    ASSERT_TRUE(secondTask(position));
}
