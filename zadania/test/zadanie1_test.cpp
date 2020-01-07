#include "zadanie1.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(rangeLoop, test1)
{
    A tab[5];

    EXPECT_EQ(20, getSumOfObjectsMeber_1(tab));
}

TEST(rangeLoop, test2)
{
    A tab[5];
    int size = sizeof(tab)/sizeof(A);

    EXPECT_EQ(20, getSumOfObjectsMeber_2(tab, size));
}

TEST(rangeLoop, test3)
{
    A tab[5];

    int size = sizeof(tab)/sizeof(A);

    changeObjectsMemberValue(tab, size);

    EXPECT_EQ(50, getSumOfObjectsMeber_2(tab, size));
}
