#include "Card.hpp"

Card::Card(std::string name, std::string description, uint manaCost, uint cardID)
:
 _name(name),
_description(description),
_manaCost(manaCost),
_cardID(cardID)
{}
