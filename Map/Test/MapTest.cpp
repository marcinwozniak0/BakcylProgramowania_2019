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

TEST_F(SquareMapTest, MapWithSize2ShouldContain1TreasureField)
{
    SquareMap map(2);
    constexpr int expectedNumberOfTreasureFields = 1;

    auto &list = map.getFields();

    int numberOfTreasureFields = 0;

    for(unsigned i = 0; i < list.size(); i++)
    {
        numberOfTreasureFields += std::count_if(list.at(i).begin(), list.at(i).end(),
            [&](const auto &field){ return field -> getType() == FieldType::Treasure; });
    }

    ASSERT_EQ(expectedNumberOfTreasureFields, numberOfTreasureFields);
}

TEST_F(SquareMapTest, MapWithSize4ShouldContain2TreasureFields)
{
    SquareMap map(4);
    constexpr int expectedNumberOfTreasureFields = 2;

    auto &list = map.getFields();

    int numberOfTreasureFields = 0;

    for(unsigned i = 0; i < list.size(); i++)
    {
        numberOfTreasureFields += std::count_if(list.at(i).begin(), list.at(i).end(),
            [&](const auto &field){ return field -> getType() == FieldType::Treasure; });
    }

    ASSERT_EQ(expectedNumberOfTreasureFields, numberOfTreasureFields);
}

TEST_F(SquareMapTest, MapWithSize2ShouldContain1FightField)
{
    SquareMap map(2);
    constexpr int expectedNumberOfFightFields = 1;
    auto &list = map.getFields();

    int numberOfFightFields = 0;

    for(unsigned i = 0; i < list.size(); i++)
    {
        numberOfFightFields += std::count_if(list.at(i).begin(), list.at(i).end(),
            [&](const auto &field){ return field -> getType() == FieldType::Fight; });
    }

    ASSERT_EQ(expectedNumberOfFightFields, numberOfFightFields);
}

TEST_F(SquareMapTest, MapWithSize4ShouldContain2FightFields)
{
    SquareMap map(4);
    constexpr int expectedNumberOfFightFields = 2;
    auto &list = map.getFields();

    int numberOfFightFields = 0;

    for(unsigned i = 0; i < list.size(); i++)
    {
        numberOfFightFields += std::count_if(list.at(i).begin(), list.at(i).end(),
            [&](const auto &field){ return field -> getType() == FieldType::Fight; });
    }

    ASSERT_EQ(expectedNumberOfFightFields, numberOfFightFields);
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