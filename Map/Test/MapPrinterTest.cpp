#include "MapPrinter.hpp"
#include "FightField.hpp"
#include "EmptyField.hpp"
#include "TreasureField.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(MapPrinterTest, PrintStandardFieldShouldReturnEmpty)
{
    MapPrinter printer;
    EmptyField emptyfield;
    ASSERT_EQ(FieldType::Empty, printer.printField(emptyfield));
}

TEST(MapPrinterTest, PrintFightFieldShouldReturnFight)
{
    MapPrinter printer;
    FightField fightfield;
    ASSERT_EQ(FieldType::Fight, printer.printField(fightfield));
}

TEST(MapPrinterTest, PrintTreasureFieldShouldReturnTreasure)
{
     MapPrinter printer;
     TreasureField treasurefield;
     ASSERT_EQ(FieldType::Treasure, printer.printField(treasurefield));
}
