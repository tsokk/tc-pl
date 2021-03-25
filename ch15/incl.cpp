#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "incl.h"

int main(int argc, char *argv[]) try {
  switch (argc) {
  case 1:
    Error::usage();
    return 1;
  case 2: {
    std::string filename{argv[1]};
    std::ifstream ifs{filename};
    if (!ifs)
      throw std::runtime_error("Error: File not found");
    std::cout << filename << '\n';
    std::vector<std::string> vs;
    Analyzer::extract_filenames(vs, ifs);
    Writer::write(vs);
    return 0;
  }
  default:
    Error::usage();
    return 1;
  }
} catch (std::exception &e) {
  std::cerr << e.what() << '\n';
}

namespace Error {
void usage() { std::cerr << "usage:\n\tshow_included <absolute file path>\n"; }
} // namespace Error

namespace Writer {
void write(const std::vector<std::string> &vs) {
  for (const auto &s : vs)
    std::cout << '\t' << s << '\n';
}
} // namespace Writer

namespace Analyzer {
void extract_filenames(std::vector<std::string> &vs, std::ifstream &ifs) {
  for (std::string s; std::getline(ifs, s);) {
    auto pos = s.find("#include");
    if (pos != std::string::npos) {
      auto start = s.find("<") + 1; // exclude `<`
      auto end = s.find(">");
      vs.push_back(s.substr(start, end - start));
    }
  }
}
} // namespace Analyzer
