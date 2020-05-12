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
  std::unique_ptr<Field> field = std::make_unique<EmptyField>();
  field->makeVisible();
  ASSERT_EQ('.',map.printField(field));
}

TEST_F(SquareMapTest, fightFieldVisiblePrint)
{
  std::unique_ptr<Field> field = std::make_unique<FightField>();
  field->makeVisible();
  ASSERT_EQ('F',map.printField(field));
}

TEST_F(SquareMapTest, treasureFieldVisiblePrint)
{
  std::unique_ptr<Field> field = std::make_unique<TreasureField>();
  field->makeVisible();
  ASSERT_EQ('T',map.printField(field));
}

TEST_F(SquareMapTest, wallFieldVisiblePrint)
{
    std::unique_ptr<Field> field = std::make_unique<WallField>();
    field->makeVisible();
    ASSERT_EQ('#', map.printField(field));
}
TEST_F(SquareMapTest, doorFieldPrint)
{
    std::unique_ptr<Field> field = std::make_unique<DoorField>();
    field->makeVisible();
    ASSERT_EQ('D', map.printField(field));
}

TEST_F(SquareMapTest, emptyFieldInvisiblePrint)
{
  std::unique_ptr<Field> field = std::make_unique<EmptyField>();
  ASSERT_EQ(' ',map.printField(field));
}

TEST_F(SquareMapTest, fightFieldInvisiblePrint)
{
  std::unique_ptr<Field> field = std::make_unique<FightField>();
  ASSERT_EQ(' ',map.printField(field));
}

TEST_F(SquareMapTest, treasureFieldInvisiblePrint)
{
  std::unique_ptr<Field> field = std::make_unique<TreasureField>();
  ASSERT_EQ(' ',map.printField(field));
}

TEST_F(SquareMapTest, wallFieldInvisiblePrint)
{
  std::unique_ptr<Field> field = std::make_unique<WallField>();
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

FieldList buildSimple5x5Map()
{
    FieldList fieldList;
    std::vector<std::unique_ptr<Field>> column;

    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));
    
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<FightField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));
    
    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<DoorField>());
    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<DoorField>());
    column.emplace_back(std::make_unique<WallField>());
    fieldList.emplace_back(std::move(column));

    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<TreasureField>());
    fieldList.emplace_back(std::move(column));

    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<TreasureField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));

    return fieldList;
}

TEST_F(SquareMapTest, mapPrint5x5_1)
{
    SquareMap map(buildSimple5x5Map());

    map.updateVisilibity(Position(3,1));
	
    ASSERT_EQ(map.getMapToPrint(Position(3,1)),"    1 2 3 4 5\n"
                                               "  #############\n"
                                               "1 #     # . . #\n"
                                               "2 #     D P . #\n"
                                               "3 #     #######\n"
                                               "4 #           #\n"
                                               "5 #           #\n"
                                               "  #############\n"
    );
}

TEST_F(SquareMapTest, mapPrint5x5_2)
{
    SquareMap map(buildSimple5x5Map());

    map.updateVisilibity(Position(0,0));
	
    ASSERT_EQ(map.getMapToPrint(Position(0,0)),"    1 2 3 4 5\n"
                                               "  #############\n"
                                               "1 # P . #     #\n"
                                               "2 # . . D     #\n"
                                               "3 # . . #     #\n"
                                               "4 # . F D     #\n"
                                               "5 # . . #     #\n"
                                               "  #############\n"
    );
}

TEST_F(SquareMapTest, mapPrint5x5_3)
{
    SquareMap map(buildSimple5x5Map());

    map.updateVisilibity(Position(3,3));
	
    ASSERT_EQ(map.getMapToPrint(Position(3,3)),"    1 2 3 4 5\n"
                                               "  #############\n"
                                               "1 #           #\n"
                                               "2 #           #\n"
                                               "3 #     #######\n"
                                               "4 #     D P T #\n"
                                               "5 #     # T . #\n"
                                               "  #############\n"
    );
}

FieldList buildSimple4x4Map()
{
    FieldList fieldList;
    std::vector<std::unique_ptr<Field>> column;

    column.emplace_back(std::make_unique<TreasureField>());
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));
    
    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<TreasureField>());
    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));
    
    column.emplace_back(std::make_unique<DoorField>());
    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<WallField>());
    column.emplace_back(std::make_unique<FightField>());
    fieldList.emplace_back(std::move(column));

    column.emplace_back(std::make_unique<EmptyField>());
    column.emplace_back(std::make_unique<FightField>());
    column.emplace_back(std::make_unique<DoorField>());
    column.emplace_back(std::make_unique<EmptyField>());
    fieldList.emplace_back(std::move(column));


    return fieldList;
}

TEST_F(SquareMapTest, mapPrint4x4_1)
{
    SquareMap map(buildSimple4x4Map());

    map.updateVisilibity(Position(0,3));
    
    ASSERT_EQ(map.getMapToPrint(Position(0,3)),"    1 2 3 4\n"
                                               "  ###########\n"
                                               "1 #         #\n"
                                               "2 #         #\n"
                                               "3 ########D##\n"
                                               "4 # P . F . #\n"
                                               "  ###########\n"
    );
}

TEST_F(SquareMapTest, mapPrint4x4_2)
{
    SquareMap map(buildSimple4x4Map());

    map.updateVisilibity(Position(1,0));
    
    ASSERT_EQ(map.getMapToPrint(Position(1,0)),"    1 2 3 4\n"
                                               "  ###########\n"
                                               "1 # T P D   #\n"
                                               "2 # . T #   #\n"
                                               "3 #######   #\n"
                                               "4 #         #\n"
                                               "  ###########\n"
    );
}

TEST_F(SquareMapTest, mapPrint4x4_3)
{
    SquareMap map(buildSimple4x4Map());

    map.updateVisilibity(Position(3,0));
    
    ASSERT_EQ(map.getMapToPrint(Position(3,0)),"    1 2 3 4\n"
                                               "  ###########\n"
                                               "1 #     D P #\n"
                                               "2 #     # F #\n"
                                               "3 #     ##D##\n"
                                               "4 #         #\n"
                                               "  ###########\n"
    );
}

TEST_F(SquareMapTest, isMoveRightPossibleShouldReturnTrue)
{
    SquareMap map(4);
    Position position(0, 0);
    ASSERT_EQ(true, map.isMovePossible(position, Direction::Right));
}

TEST_F(SquareMapTest, isMoveRightPossibleShouldReturnFalse)
{
    SquareMap map(4);
    Position position(3, 0);
    ASSERT_EQ(false, map.isMovePossible(position, Direction::Right));
}

TEST_F(SquareMapTest, isMoveLeftPossibleShouldReturnTrue)
{
    SquareMap map(4);
    Position position(1, 1);
    ASSERT_EQ(true, map.isMovePossible(position, Direction::Left));
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

TEST_F(SquareMapTest, isMoveUpPossibleShouldReturnFalse)
{
    SquareMap map(4);
    Position position(0, 0);
    ASSERT_EQ(false, map.isMovePossible(position, Direction::Up));
}

TEST_F(SquareMapTest, isMoveDownPossibleShouldReturnTrue)
{
    SquareMap map(4);
    Position position(2, 2);
    ASSERT_EQ(true, map.isMovePossible(position, Direction::Down));
}

TEST_F(SquareMapTest, isMoveDownPossibleShouldReturnFalse)
{
    SquareMap map(4);
    Position position(3, 3);
    ASSERT_EQ(false, map.isMovePossible(position, Direction::Down));
}

TEST_F(SquareMapTest, makeFightFieldEmpty1)
{
    SquareMap map(2);
    Position position(0, 0);
    auto &fields = const_cast<FieldList &>(map.getFields());
    fields.at(0).at(0) = std::make_unique<FightField>();
    map.makeFieldEmpty(position);
    ASSERT_EQ(FieldType::Empty, fields.at(0).at(0) -> getType());
}

TEST_F(SquareMapTest, makeTreasureFieldEmpty)
{
    SquareMap map(2);
    const Position position(0, 0);
    auto& fields = const_cast<FieldList &>(map.getFields());
    fields.at(0).at(0) = std::make_unique<TreasureField>();
    map.makeFieldEmpty(position);
    ASSERT_EQ(FieldType::Empty, fields.at(0).at(0) -> getType());
}

TEST_F(SquareMapTest, makeTreasureFieldEmpty2)
{
    SquareMap map(2);
    const Position position(2, 0);
    try
    {
        map.makeFieldEmpty(position);
    }
    catch(const std::out_of_range& err)
    {
        std::cout << "Out of range" << std::endl;
    }
    EXPECT_THROW(map.makeFieldEmpty(position), std::out_of_range);
}

TEST_F(SquareMapTest, makeTreasureFieldEmpty3)
{
    SquareMap map(2);
    const Position position(0, 2);
    try
    {
        map.makeFieldEmpty(position);
    }
    catch(const std::out_of_range& err)
    {
        std::cout << "Out of range" << std::endl;
    }
    EXPECT_THROW(map.makeFieldEmpty(position), std::out_of_range);
}

TEST_F(SquareMapTest, makeTreasureFieldEmpty4)
{
    SquareMap map(2);
    const Position position(-1, 0);
    try
    {
        map.makeFieldEmpty(position);
    }
    catch(const std::out_of_range& err)
    {
        std::cout << "Out of range" << std::endl;
    }
    EXPECT_THROW(map.makeFieldEmpty(position), std::out_of_range);
}

TEST_F(SquareMapTest, makeTreasureFieldEmpty5)
{
    SquareMap map(2);
    const Position position(0, -1);
    try
    {
        map.makeFieldEmpty(position);
    }
    catch(const std::out_of_range& err)
    {
        std::cout << "Out of range" << std::endl;
    }
    EXPECT_THROW(map.makeFieldEmpty(position), std::out_of_range);
}
