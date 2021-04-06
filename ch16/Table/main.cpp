#include "Table.h"
#include <iostream>

int main()
{
  Table tbl = Table{};
  tbl.add_symbol("pi", 3.1415926535897932385);
  tbl.add_symbol("e", 2.7182818284590452354);
  std::cout << tbl.symbol("pi") << '\n';
}

