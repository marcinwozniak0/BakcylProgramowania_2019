#include "FieldTypes.hpp"
#include "SquareMap.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(Maptest, quantityOfMapColumnsShouldEqualMapSize)
{
    constexpr auto mapSize = 8u;
    SquareMap map(mapSize);

    ASSERT_EQ(map.getFields().size(), mapSize);
}

TEST(Maptest, quantityOfFieldsInFirstColumnShouldEqualMapSize)
{
    constexpr auto mapSize = 8u;
    SquareMap map(mapSize);

    ASSERT_EQ(map.getFields().at(0).size(), mapSize);
}

TEST(Maptest, fieldShouldBeEmpty)
{
    constexpr auto mapSize = 1u;
    SquareMap map(mapSize);

    auto& field = map.getFields().at(0).at(0);
    ASSERT_EQ(field->getType(), FieldType::Empty);
}
