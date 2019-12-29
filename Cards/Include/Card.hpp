#pragma once
#include <iostream>

class Card
{
	public:
		virtual std::string useCard();
};

class MonsterCard :public Card
{
	public:
		int hp, dmg;
		MonsterCard(int = 20,int = 10);
		virtual std::string useCard();
};

class SpellCard :public Card
{
	public:
		virtual std::string useCard();
};
	