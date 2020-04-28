#include "Table.hpp"

 Table::Table()
{
  TableDeck _playersTableSite(5);
  TableDeck _computerTableSite(5);
  Deck _playersDiscardDeck;
  Deck _computerDiscardDeck;
  std::shared_ptr<TableDeck> playersTableSite = std::make_shared<TableDeck>(_playersTableSite);
  std::shared_ptr<TableDeck> computerTableSite = std::make_shared<TableDeck>(_computerTableSite);
  std::shared_ptr<Deck> playersDiscardDeck = std::make_shared<Deck>(_playersDiscardDeck);
  std::shared_ptr<Deck> computerDiscardDeck = std::make_shared<Deck>(_computerDiscardDeck);
}
