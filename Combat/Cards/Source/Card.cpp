#include "Card.hpp"

Card::Card(std::string name, uint id, std::string description, uint manaCost)
  :_name(name)
  ,_id(id)
  ,_description(description)
  ,_manaCost(manaCost)
{}

std::string Card::getName() const
{
   return _name;
}

uint Card::getId() const
{
   return _id;
}

const bool operator== (const Card& lhs, const Card& rhs)
{
   return lhs.getName() == rhs.getName() && lhs.getId() == rhs.getId();
}
