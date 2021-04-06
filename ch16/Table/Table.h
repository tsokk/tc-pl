#include <map>
#include <string>

class Table {
public:
  Table() {}
  void add_symbol(std::string, double);
  double symbol(std::string);
private:
  std::map<std::string, double> table;
};
