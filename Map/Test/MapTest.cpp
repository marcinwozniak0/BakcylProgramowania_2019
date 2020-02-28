#include "FieldTypes.hpp"
#include "SquareMap.hpp"
#include "EmptyField.hpp"
#include "FightField.hpp"
#include "TreasureField.hpp"
#include "WallField.hpp"
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

TEST_F(SquareMapTest, emptyFieldPrint)
{
  EmptyField field;
  ASSERT_EQ('.',map.printField(field));
}

TEST_F(SquareMapTest, fightFieldPrint)
{
  FightField field;
  ASSERT_EQ('F',map.printField(field));
}

TEST_F(SquareMapTest, treasureFieldPrint)
{
  TreasureField field;
  ASSERT_EQ('T',map.printField(field));
}

TEST_F(SquareMapTest, wallFieldPrint)
{
  WallField field;
  ASSERT_EQ('#',map.printField(field));
}
