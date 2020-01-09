#include "Card.hpp"
#include <iostream>

MonsterCard::MonsterCard(int h, int s)
    :
    hp(h) ,
    strength(s)
{

}

std::string Card::useCard()
{
    return "";
}

std::string MonsterCard::takeDamage()
{
    return "someDamageTaken";
}

std::string MonsterCard::useCard()
{
    return "useMonsterCard";
}

std::string SpellCard::useCard()
{
    return "useSpellCard";
}
