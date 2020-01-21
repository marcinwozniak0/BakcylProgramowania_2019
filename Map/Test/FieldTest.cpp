#include "FieldTestClass.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(FieldTest, DefaultPrintabilityShouldBeFalse)
{
    FieldTestClass testField;
    ASSERT_FALSE(testField.isPrintable());
}

TEST(FieldTest, makePrintableShouldChangePrintabilityToTrue)
{
    FieldTestClass testField;
    testField.makePrintable();
    ASSERT_TRUE(testField.isPrintable());
}
