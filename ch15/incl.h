namespace Writer {
void write(const std::vector<std::string> &vs);
}

namespace Analyzer {
void extract_filenames(std::vector<std::string> &vs, std::ifstream &ifs);
}

namespace Error {
void usage();
}
