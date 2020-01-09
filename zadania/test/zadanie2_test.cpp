#include <gtest/gtest.h>

#include "zadanie2.hpp"

TEST(lambda, test1)
{
    std::vector<int> vec{1,2,3,4,5,6};

    EXPECT_EQ(3, getNumOfOddValues(vec));
}

TEST(lambda, test2)
{
    std::vector<int> vec{2,4,6};

    EXPECT_EQ(0, getNumOfOddValues(vec));
}

TEST(lambda, test3)
{
    std::vector<int> vec{1,2,3,4,5,6};

    reverse(vec);

    std::vector<int> reversedVec{6,5,4,3,2,1};

    EXPECT_EQ(reversedVec, vec);
}

TEST(lambda, test4)
{
    std::vector<int> vec{};

    reverse(vec);

    std::vector<int> reversedVec{};

    EXPECT_EQ(reversedVec, vec);
}

//TEST(lambda, test5)
//{
//    std::vector<int> vec{6, 4, 1};

//    EXPECT_FALSE(isAllOfValuesAreEven(vec));
//}

//TEST(lambda, test6)
//{
//    std::vector<int> vec{2,4};

//    EXPECT_TRUE(isAllOfValuesAreEven(vec));
//}
