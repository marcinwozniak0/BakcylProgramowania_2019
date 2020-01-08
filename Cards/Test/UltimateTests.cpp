#include "Ultimate.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

class Ultimate_Mage_Race_Test : public  Test
{
public:
    Ultimate_Mage_Race_Test()
     : ultimateMageRace(500, 20){}

    Ultimate_Mage_Race ultimateMageRace;
};

class Ultimate_Warrior_Race_Test : public  Test
{
public:
    Ultimate_Warrior_Race_Test()
     : ultimateWarriorRace(400, 10){}

    Ultimate_Warrior_Race ultimateWarriorRace;
};


TEST(Ultimate_Test, ItShouldReturnString_useMageUlt)
{
    Ultimate_Mage_Race ultimate_mage2;
	ASSERT_EQ("useMageUlt", ultimate_mage2.useUlt());
}

TEST(Ultimate_Test, ItShouldReturnString_useWarriorUlt)
{
    Ultimate_Warrior_Race ultimate_warrior3;
	ASSERT_EQ("useWarriorUlt", ultimate_warrior3.useUlt());
}

TEST(Ultimate_Test, ItShouldReturnDefaulMageHealAndDmgValue)
{
  Ultimate_Mage_Race ultimate_mage4;
	ASSERT_EQ(10, ultimate_mage4.heal + ultimate_mage4.dmg);
}

TEST(Ultimate_Test, ItShouldReturnDefaulWarriorHealAndDmgValue)
{
  Ultimate_Warrior_Race ultimate_warrior5;
	ASSERT_EQ(9, ultimate_warrior5.heal + ultimate_warrior5.dmg);
}

TEST(Ultimate_Test, ItShouldBeChosenWarriorDmgAndHpValue)
{
  Ultimate_Warrior_Race ultimate_warrior6(1,2);
	ASSERT_EQ(1, ultimate_warrior6.heal);
	ASSERT_EQ(2, ultimate_warrior6.dmg);
}

TEST(Ultimate_Test, ItShouldBeChosenMageDmgAndHpValue)
{
  Ultimate_Warrior_Race ultimate_mage7(3,4);
	ASSERT_EQ(3, ultimate_mage7.heal);
	ASSERT_EQ(4, ultimate_mage7.dmg);
}

TEST_F(Ultimate_Mage_Race_Test, ctorTest)
{
    ASSERT_TRUE(true);
}

TEST_F(Ultimate_Mage_Race_Test, shouldUseUltCorrectly)
{
    ASSERT_EQ("useMageUlt", ultimateMageRace.useUlt());
}

TEST_F(Ultimate_Warrior_Race_Test, ctorTest)
{
    ASSERT_TRUE(true);
}

TEST_F(Ultimate_Warrior_Race_Test, shouldUseUltCorrectly)
{
    ASSERT_EQ("useWarriorUlt", ultimateWarriorRace.useUlt());
}
