#pragma once
#include "../../Decks/Include/LimitedDeck.hpp"
#include <string>
#include <memory>
#include <vector>

using Card = std::string;

struct Table
{
public:
   TableDeck _playersTableSite;
   TableDeck _computerTableSite;
   Deck _playersDiscardDeck;
   Deck _computerDiscardDeck;
   std::shared_ptr<TableDeck> playersTableSite;
   std::shared_ptr<TableDeck> computerTableSite;
   std::shared_ptr<Deck> playersDiscardDeck;
   std::shared_ptr<Deck> computerDiscardDeck;
   Table();
};
