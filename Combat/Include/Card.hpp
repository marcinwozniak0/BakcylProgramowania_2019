#pragma once
#include <string>

class Card
{
protected:
   std::string _name;
   uint _id;
   std::string _description;
   uint _manaCost;
   Card(std::string name, uint id, std::string description, uint manaCost);
 public:
   std::string getName() const;
   uint getId() const;
};

const bool operator== (const Card& lhs, const Card& rhs);
