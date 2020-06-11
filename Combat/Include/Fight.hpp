#pragma once
#include "Deck.hpp"
#include <memory>

class Fight
{
	std::unique_ptr<Table> _tablePtr;
	void printEndGame() const;
	void printFight(Player* p1, Player* p2) const;
};
