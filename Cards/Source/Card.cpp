#include "Card.hpp"
#include <iostream>

std::string Card::useCard()
{
	return "";
}

std::string MonsterCard::useCard()
{
	return "useMonsterCard";
}

std::string SpellCard::useCard()
{
	return "useSpellCard";
}