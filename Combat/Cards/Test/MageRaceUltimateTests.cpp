#include "MageRaceUltimate.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

class Ultimate_Mage_Race_Test : public  Test
{
public:
    Ultimate_Mage_Race_Test()
    : ultimateMageRace(500, 20){}

    Ultimate_Mage_Race ultimateMageRace;
};

TEST(Ultimate_Test, ItShouldReturnString_useMageUlt)
{
  Ultimate_Mage_Race ultimate_mage2;
	ASSERT_EQ("useMageUlt", ultimate_mage2.useUlt());
}


TEST_F(Ultimate_Mage_Race_Test, ctorTest)
{
    ASSERT_TRUE(true);
}

TEST_F(Ultimate_Mage_Race_Test, shouldUseUltCorrectly)
{
    ASSERT_EQ("useMageUlt", ultimateMageRace.useUlt());
}
