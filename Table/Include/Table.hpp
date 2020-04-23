#pragma once
#include <string>
#include <vector>

using Card = std::string;

struct Table
{
 public:
   std::vector<Card> _playerstable;
   std::vector<Card> _aitable;
};
