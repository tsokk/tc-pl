#include <iostream>

int say_hello(int argc, char* argv[])
{
  if (argc > 255)
    std::cerr << "less than 255 arguments expected\n";

  switch(argc) {
    case 1:
      std::cerr << "provide at least one argument\n";
      return 1;
    case 2:
      std::cout << "Hello, " << argv[1] << "!\n";
      break;
    default:
      for (auto i = 1; i <= argc - 1; ++i)
        std::cout << "Hello, " << argv[i] << "!\n";
  }
  return 0;
}

int main(int argc, char* argv[])
{
  say_hello(argc, argv);
}

