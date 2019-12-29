#include "Card.hpp"
#include <iostream>

std::string Card::useCard()
{
	return "";
}

MonsterCard::MonsterCard(int h, int d)
{
	hp = h;
	dmg = d;
}

std::string MonsterCard::useCard()
{
	return "useMonsterCard";
}

std::string SpellCard::useCard()
{
	return "useSpellCard";
}