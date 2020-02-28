#include "Field.hpp"
#include "DoorField.hpp"
#include "EmptyField.hpp"
#include "FightField.hpp"
#include "TreasureField.hpp"
#include "WallField.hpp"
#include <gtest/gtest.h>

class FieldTestClass : public Field
{
    void action()
    {
    }

    FieldType getType() const
    {
        return FieldType::Empty;
    }
};

using namespace ::testing;

TEST(FieldTest, fieldShouldBeInvisibleByDefault)
{
    FieldTestClass testField;
    ASSERT_FALSE(testField.isVisible());
}

TEST(FrintabilityieldTest, makeVisableShouldChangeVisilibityToTrue)
{
    FieldTestClass testField;
    testField.makeVisible();
    ASSERT_TRUE(testField.isVisible());
}




TEST(FieldTypeTest, FightFieldTypeShouldBeDoorField)
{
    FightField testField;
    ASSERT_EQ(testField.getType(), FieldType::Fight);
}

TEST(FieldTypeTest, EmptyFieldTypeShouldBeDoorField)
{
    EmptyField testField;
    ASSERT_EQ(testField.getType(), FieldType::Empty);
}

TEST(FieldTypeTest, TreasureFieldTypeShouldBeDoorField)
{
    TreasureField testField;
    ASSERT_EQ(testField.getType(), FieldType::Treasure);
}

TEST(FieldTypeTest, WallFieldTypeShouldBeDoorField)
{
    WallField testField;
    ASSERT_EQ(testField.getType(), FieldType::Wall);
}
TEST(FieldTypeTest, DoorFieldTypeShouldBeDoorField)
{
    DoorField testField;
    ASSERT_EQ(testField.getType(), FieldType::Door);
}
