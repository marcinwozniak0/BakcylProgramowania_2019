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

TEST_F(SquareMapTest, emptyFieldVisiblePrint)
{
  EmptyField field;
  field.makeVisible();
  ASSERT_EQ('.',map.printField(field));
}

TEST_F(SquareMapTest, fightFieldVisiblePrint)
{
  FightField field;
  field.makeVisible();
  ASSERT_EQ('F',map.printField(field));
}

TEST_F(SquareMapTest, treasureFieldVisiblePrint)
{
  TreasureField field;
  field.makeVisible();
  ASSERT_EQ('T',map.printField(field));
}

TEST_F(SquareMapTest, wallFieldVisiblePrint)
{
  WallField field;
  field.makeVisible();
  ASSERT_EQ('#',map.printField(field));
}

TEST_F(SquareMapTest, emptyFieldInvisiblePrint)
{
  EmptyField field;
  ASSERT_EQ(' ',map.printField(field));
}

TEST_F(SquareMapTest, fightFieldInvisiblePrint)
{
  FightField field;
  ASSERT_EQ(' ',map.printField(field));
}

TEST_F(SquareMapTest, treasureFieldInvisiblePrint)
{
  TreasureField field;
  ASSERT_EQ(' ',map.printField(field));
}

TEST_F(SquareMapTest, wallFieldInvisiblePrint)
{
  WallField field;
  ASSERT_EQ(' ',map.printField(field));
}