#include "Field.hpp"
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
