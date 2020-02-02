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

TEST_F(SquareMapTest, fieldShouldBeEmpty)
{
    const auto& field = map.getFields().at(0).at(0);
    ASSERT_EQ(field->getType(), FieldType::Empty);
}
