#include "MapPrinter.hpp"
#include "FightField.hpp"
#include "EmptyField.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(MapPrinterTest, PrintStandardFieldShouldReturnDot)
{
    MapPrinter printer;
    EmptyField emptyfield;
    ASSERT_EQ('0', printer.printField(emptyfield));
}

TEST(MapPrinterTest, PrintFightFieldShouldReturnF)
{
    MapPrinter printer;
    FightField fightfield;
    ASSERT_EQ('F', printer.printField(fightfield));
}

// TEST(MapPrinterTest, PrintTreasureFieldShouldReturnT)
// {
//     MapPrinter printer;
//     Field TreasureField;
//     ASSERT_EQ('T', printer.printField(fieldTreasure));
// }
