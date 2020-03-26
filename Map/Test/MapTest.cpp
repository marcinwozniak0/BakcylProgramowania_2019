#include "DoorField.hpp"
#include "EmptyField.hpp"
#include "FieldTypes.hpp"
#include "FightField.hpp"
#include "SquareMap.hpp"
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

    for(const auto& column : list)
    {
        numberOfTreasureFields += std::count_if(column.begin(), column.end(),
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

    for(const auto& column : list)
    {
        numberOfTreasureFields += std::count_if(column.begin(), column.end(),
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

    for(const auto& column : list)
    {
        numberOfFightFields += std::count_if(column.begin(), column.end(),
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

    for(const auto& column : list)
    {
        numberOfFightFields += std::count_if(column.begin(), column.end(),
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
    ASSERT_EQ('#', map.printField(field));
}
TEST_F(SquareMapTest, doorFieldPrint)
{
    DoorField field;
    field.makeVisible();
    ASSERT_EQ('D', map.printField(field));
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

FieldList buildSimpleThreeRoomsMap()
{
    FieldList fieldList;
    std::vector<std::unique_ptr<Field>> column;

    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));

    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<DoorField>());
    column.emplace_back(std::make_unique<WallField>());
    fieldList.emplace_back(std::move(column));

    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));

    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<DoorField>());
    column.emplace_back(std::make_unique<WallField>());
    fieldList.emplace_back(std::move(column));

    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));

    return fieldList;

}

TEST_F(SquareMapTest, mapShouldBeInvisibleByDefault)
{
    SquareMap map(buildSimpleThreeRoomsMap());
    constexpr int expectedNumberOfVisibleFields = 0;
    auto &fieldList = map.getFields();

    int numberOfVisibleFields = 0;

    for(const auto& column : fieldList)
    {
        numberOfVisibleFields += std::count_if(column.begin(), column.end(),
            [&](const auto &field){ return field->isVisible(); });
    }

    ASSERT_EQ(expectedNumberOfVisibleFields, numberOfVisibleFields);
}

TEST_F(SquareMapTest, RoomWithPlayerShouldBeVisible)
{
    SquareMap map(buildSimpleThreeRoomsMap());
    constexpr int expectedNumberOfVisibleFields = 6;

    int numberOfVisibleFields = 0;

    map.updateVisilibity(Position(0,0));

    auto &fieldList = map.getFields();
    for(const auto& column : fieldList)
    {
        numberOfVisibleFields += std::count_if(column.begin(), column.end(),
            [&](const auto &field){ return field->isVisible(); });
    }

    ASSERT_EQ(expectedNumberOfVisibleFields, numberOfVisibleFields);
}

TEST_F(SquareMapTest, WhenPlayerOnDoorBothRoomsShouldBeVisible)
{
    SquareMap map(buildSimpleThreeRoomsMap());
    constexpr int expectedNumberOfVisibleFields = 12;

    int numberOfVisibleFields = 0;

    map.updateVisilibity(Position(1,1));

    auto &fieldList = map.getFields();
    for(const auto& column : fieldList)
    {
        numberOfVisibleFields += std::count_if(column.begin(), column.end(),
            [&](const auto &field){ return field->isVisible(); });
    }

    ASSERT_EQ(expectedNumberOfVisibleFields, numberOfVisibleFields);
}

TEST_F(SquareMapTest, seenDoorsAndWallsShouldStayVisible)
{
    SquareMap map(buildSimpleThreeRoomsMap());
    constexpr int expectedNumberOfVisibleFields = 9;

    int numberOfVisibleFields = 0;

    map.updateVisilibity(Position(1,1));
    map.updateVisilibity(Position(0,0));

    auto &fieldList = map.getFields();
    for(const auto& column : fieldList)
    {
        numberOfVisibleFields += std::count_if(column.begin(), column.end(),
            [&](const auto &field){ return field->isVisible(); });
    }

    ASSERT_EQ(expectedNumberOfVisibleFields, numberOfVisibleFields);
}

TEST_F(SquareMapTest, isMoveRightPossibleShouldReturnTrue)
{
    SquareMap map(4);
    Position position(0, 0);
    ASSERT_EQ(true, map.isMovePossible(position, Direction::Right));
}

TEST_F(SquareMapTest, isMoveLeftPossibleShouldReturnFalse)
{
    SquareMap map(4);
    Position position(0, 0);
    ASSERT_EQ(false, map.isMovePossible(position, Direction::Left));
}

TEST_F(SquareMapTest, isMoveUpPossibleShouldReturnTrue)
{
    SquareMap map(4);
    Position position(2, 2);
    ASSERT_EQ(true, map.isMovePossible(position, Direction::Up));
}

TEST_F(SquareMapTest, isMoveDownPossibleShouldReturnTrue)
{
    SquareMap map(4);
    Position position(2, 2);
    ASSERT_EQ(true, map.isMovePossible(position, Direction::Down));
}