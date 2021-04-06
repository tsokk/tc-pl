#include "Table.h"

void Table::add_symbol(std::string s, double d)
{
  table[s] = d;
}

double Table::symbol(std::string s)
{
  return table[s];
}

