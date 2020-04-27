#pragma once
#include <string>

class Card
{
protected:
   std::string _name;
   std::string _description;
   uint _manaCost;
   Card(std::string name, std::string description, uint manaCost);
};
