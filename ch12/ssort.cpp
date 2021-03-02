#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct User {
  std::string name;
  std::string id;
  int dept;
};

std::vector<User> heads = {
    {"Ritchie D.M", "dmr", 11271},    {"Sethi R.", "ravi", 11272},
    {"Szymanski T.G.", "tgs", 11273}, {"Schryer N.L.", "nls", 11274},
    {"Schryer N.L.", "nls", 11275},   {"Kernighan, B.W.", "bwk", 11276}};

void print_id(std::vector<User> &v) {
  for (auto &x : v)
    std::cout << x.name << '\t' << x.id << '\t' << x.dept << '\n';
}

int main() {
  std::cout << "Heads in alphabetical order:\n";
  std::sort(heads.begin(), heads.end(),
            [](const User &x, const User &y) { return x.name < y.name; });
  print_id(heads);
	std::cout << '\n';

  std::cout << "Heads in order of department number:\n";
  std::sort(heads.begin(), heads.end(),
            [](const User &x, const User &y) { return x.dept < y.dept; });
  print_id(heads);
}
