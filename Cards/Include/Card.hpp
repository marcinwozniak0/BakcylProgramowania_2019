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
		virtual std::string useCard();
};

class SpellCard :public Card
{
	public:
		virtual std::string useCard();
};
	