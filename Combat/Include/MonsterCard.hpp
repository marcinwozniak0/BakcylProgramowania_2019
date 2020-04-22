#pragma once
#include "Card.hpp"
#include <iostream>

class MonsterCard : public Card
{
    protected:
        int hp;
        int strength;
    public:
        MonsterCard(int = 20,int = 10);
        std::string useCard() override;
        int takeDamage(int damagePoints);
};
