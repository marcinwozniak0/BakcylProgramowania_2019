#include "Card.hpp"

Card::Card(std::string name, std::string description, uint manaCost)
  :_name(name)
  ,_description(description)
  ,_manaCost(manaCost)
{}
