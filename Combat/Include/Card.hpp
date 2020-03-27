#pragma once
#include <string>

class Card
{
    public:
      std::string _name;
      std::string _description;
      uint _manaCost;
      int _cardID[2]; //cardID[0] - monster(0)/spell(1); cardID[1] - card's number

};
