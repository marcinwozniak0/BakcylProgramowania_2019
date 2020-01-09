#pragma once
#include <iostream>

class Card
{
    public:
        virtual std::string useCard() = 0;
};

class MonsterCard : public Card
{
    private:
        int hp;
        int strength;    
    public:
        MonsterCard(int = 20,int = 10);
        std::string useCard() override;
};

class SpellCard : public Card
{
    public:
        std::string useCard() override;
};
