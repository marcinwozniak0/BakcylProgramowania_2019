#include "Map.hpp"
#include "FieldTypes.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(Maptest, quantityOfMapColumnsShouldEqualMapSize)
{
    Map map(8);
    ASSERT_EQ(map.getFields().size(), 8);
}

TEST(Maptest, quantityOfFieldsInFirstColumnShouldEqualMapSize)
{
    Map map(8);
    ASSERT_EQ(map.getFields()[0].size(), 8);
}

TEST(Maptest, fieldShouldBeEmpty)
{
    Map map(1);
    auto &field = map.getFields().at(0).at(0);
    ASSERT_EQ(field->getType(), FieldType::Empty);
}
