#include "Table.hpp"

 Table::Table()
 :
 _playersTableSite(5),
 _computerTableSite(5)
  {
    playersTableSite = std::make_shared<TableDeck>(_playersTableSite);
    computerTableSite = std::make_shared<TableDeck>(_computerTableSite);
    playersDiscardDeck = std::make_shared<Deck>(_playersDiscardDeck);
    computerDiscardDeck = std::make_shared<Deck>(_computerDiscardDeck);
  }
