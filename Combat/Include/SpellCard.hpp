#pragma once
#include "Card.hpp"
#include <iostream>

class SpellCard : public Card
{
    public:
        std::string useCard() override;
};
