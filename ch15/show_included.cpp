#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void print(const std::vector<std::string> &vs);
void extract_filenames(std::vector<std::string> &vs, std::ifstream &ifs);
void usage();

int main(int argc, char *argv[])
try {
  switch (argc) {
  case 1:
    usage();
    return 1;
  case 2:
  {
    std::string filename {argv[1]};
    std::ifstream ifs {filename};
    if (!ifs)
      throw std::runtime_error("Error: File not found");
    std::cout << filename << '\n';
    std::vector<std::string> vs;
    extract_filenames(vs, ifs);
    print(vs);
    return 0;
  }
  default:
    usage();
    return 1;
  }
}
catch (std::exception &e) {
  std::cerr << e.what() << '\n';
}

void usage() {
  std::cerr << "usage:\n\tshow_included <absolute file path>\n";
}

void print(const std::vector<std::string> &vs) {
  for (const auto &s : vs)
    std::cout << '\t' << s << '\n';
}

void extract_filenames(std::vector<std::string> &vs, std::ifstream &ifs) {
  for (std::string s; std::getline(ifs, s); ) {
    auto pos = s.find("#include");
    if (pos != std::string::npos) {
      auto start = s.find("<") + 1;  // exclude `<`
      auto end = s.find(">");
      vs.push_back(s.substr(start, end - start));
    }
  }
}
