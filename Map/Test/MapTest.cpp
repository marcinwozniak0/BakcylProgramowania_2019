#include "FieldTypes.hpp"
#include "SquareMap.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

namespace
{
constexpr auto mapSize = 8u;
}

class SquareMapTest : public Test
{
protected:
    SquareMapTest() : map(mapSize)
    {
    }
    SquareMap map;
};

TEST_F(SquareMapTest, quantityOfMapColumnsShouldEqualMapSize)
{
    ASSERT_EQ(map.getFields().size(), mapSize);
}

TEST_F(SquareMapTest, quantityOfFieldsInFirstColumnShouldEqualMapSize)
{
    ASSERT_EQ(map.getFields().at(0).size(), mapSize);
}

TEST_F(SquareMapTest, CheckIfMapContainsTreasureField)
{
    SquareMap map(2);
    auto &list = map.getFields();

    int numberOfTreasureFields = 0;

    for(unsigned i = 0; i < list.size(); i++)
    {
        numberOfTreasureFields += std::count_if(list.at(i).begin(), list.at(i).end(),
            [&](const auto &field){ return field -> getType() == FieldType::Treasure; });
    }

    ASSERT_EQ(1, numberOfTreasureFields);
}

TEST_F(SquareMapTest, CheckIfMapContainsTreasureFields)
{
    SquareMap map(4);
    auto &list = map.getFields();

    int numberOfTreasureFields = 0;

    for(unsigned i = 0; i < list.size(); i++)
    {
        numberOfTreasureFields += std::count_if(list.at(i).begin(), list.at(i).end(),
            [&](const auto &field){ return field -> getType() == FieldType::Treasure; });
    }

    ASSERT_EQ(2, numberOfTreasureFields);
}

TEST_F(SquareMapTest, CheckIfMapContainsFightField)
{
    SquareMap map(2);
    auto &list = map.getFields();

    int numberOfFightFields = 0;

    for(unsigned i = 0; i < list.size(); i++)
    {
        numberOfFightFields += std::count_if(list.at(i).begin(), list.at(i).end(),
            [&](const auto &field){ return field -> getType() == FieldType::Fight; });
    }

    ASSERT_EQ(1, numberOfFightFields);
}

TEST_F(SquareMapTest, CheckIfMapContainsFightFields)
{
    SquareMap map(4);
    auto &list = map.getFields();

    int numberOfFightFields = 0;

    for(unsigned i = 0; i < list.size(); i++)
    {
        numberOfFightFields += std::count_if(list.at(i).begin(), list.at(i).end(),
            [&](const auto &field){ return field -> getType() == FieldType::Fight; });
    }

    ASSERT_EQ(2, numberOfFightFields);
}