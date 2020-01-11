#include "WarriorRaceUltimate.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

class Ultimate_Warrior_Race_Test : public  Test
{
public:
    Ultimate_Warrior_Race_Test()
    : ultimateWarriorRace(400, 10){}

    Ultimate_Warrior_Race ultimateWarriorRace;
};

TEST(Ultimate_Test, ItShouldReturnString_useWarriorUlt)
{
  Ultimate_Warrior_Race ultimate_warrior3;
	ASSERT_EQ("useWarriorUlt", ultimate_warrior3.useUlt());
}

TEST_F(Ultimate_Warrior_Race_Test, ctorTest)
{
    ASSERT_TRUE(true);
}

TEST_F(Ultimate_Warrior_Race_Test, shouldUseUltCorrectly)
{
    ASSERT_EQ("useWarriorUlt", ultimateWarriorRace.useUlt());
}
