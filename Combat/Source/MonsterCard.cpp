#include "MonsterCard.hpp"
#include <iostream>

MonsterCard::MonsterCard(int h, int s)
    :
    hp(h) ,
    strength(s)
{

}

int MonsterCard::takeDamage(int damagePoints)
{
    hp -= damagePoints;
    return  hp;
}

std::string MonsterCard::useCard()
{
    return "useMonsterCard";
}
