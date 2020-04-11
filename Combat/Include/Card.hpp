#pragma once
#include <string>

class Card
{
    public:
      std::string _name;
      std::string _description;
      uint _manaCost;
      uint _cardID; //cardID[0] - monster(1)/spell(2); cardID[1] - card's number
      Card(std::string name, std::string description, uint manaCostuint, uint cardID);
};
