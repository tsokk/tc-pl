#include <iostream>
#include <fstream>
#include <string>

void write(char* fname)
  /*
   * read text from file `fname` and write its
   * contents to standard output
   *
   * precondition: file `fname` exists
   * postcondition: write operation succeeds
   */
{
  std::ifstream ifs {fname};
  if (!ifs)
    std::cerr << "file does not exits\n";
  for (std::string s; getline(ifs, s); )
    std::cout << s << '\n';
}

int write_out(int argc, char* argv[])
  /*
   * call write function with `argc` number of times
   *
   * precondition: argc is in range [2,255)
   * postcondition: returns 0 or 1 indicating
   *                success or failure
   */
{
  if (argc > 255)
    std::cerr << "less than 255 arguments expected\n";

  switch(argc) {
    case 1:
      std::cerr << "provide at least one argument\n";
      return 1;
    case 2:
      write(argv[1]);
      break;
    default:
      for (auto i = 1; i <= argc - 1; ++i)
        write(argv[i]);
  }
  return 0;
}

int main(int argc, char* argv[])
{
  write_out(argc, argv);
}

