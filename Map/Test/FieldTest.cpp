#include "EmptyField.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(FieldTest, makePrintable_ShouldChangePrintability)
{
    EmptyField emptyfield;
    ASSERT_FALSE(emptyfield.isPrintable());
    emptyfield.makePrintable();
    ASSERT_TRUE(emptyfield.isPrintable());
}
