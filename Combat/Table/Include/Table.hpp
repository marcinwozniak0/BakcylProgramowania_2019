#pragma once
#include "LimitedDeck.hpp"
#include <string>
#include <memory>
#include <vector>

struct Table
{
  TableDeck _playersTableSite;
  TableDeck _computerTableSite;
  Deck _playersDiscardDeck;
  Deck _computerDiscardDeck;
public:
   std::shared_ptr<TableDeck> playersTableSite;
   std::shared_ptr<TableDeck> computerTableSite;
   std::shared_ptr<Deck> playersDiscardDeck;
   std::shared_ptr<Deck> computerDiscardDeck;
   Table();
};
