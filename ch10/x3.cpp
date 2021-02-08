#include <iostream>

using namespace std;

int main() {
  cout << '\n';
  cout << "bitwise and\n";
  cout << "0 & 1" << '\t' << (0 & 1) << '\n';
  cout << "1 & 0" << '\t' << (1 & 0) << '\n';
  cout << "1 & 1" << '\t' << (1 & 1) << '\n';
  cout << "0 & 0" << '\t' << (0 & 0) << '\n';
  cout << '\n';

  cout << "bitwise inclusive-or\n";
  cout << "0 | 1" << '\t' << (0 | 1) << '\n';
  cout << "1 | 0" << '\t' << (1 | 0) << '\n';
  cout << "1 | 1" << '\t' << (1 | 1) << '\n';
  cout << "0 | 0" << '\t' << (0 | 0) << '\n';
  cout << '\n';

  cout << "bitwise exclusive-or\n";
  cout << "0 ^ 1" << '\t' << (0 ^ 1) << '\n';
  cout << "1 ^ 0" << '\t' << (1 ^ 0) << '\n';
  cout << "1 ^ 1" << '\t' << (1 ^ 1) << '\n';
  cout << "0 ^ 0" << '\t' << (0 ^ 0) << '\n';
  cout << '\n';

  cout << "bitwise complement\n";
  cout << "~1" << '\t' << (~1) << '\n';
  cout << "~0" << '\t' << (~0) << '\n';
  cout << '\n';

  cout << "leftshift\n";
  cout << "0 << 1" << '\t' << (0 << 1) << '\n';
  cout << "1 << 0" << '\t' << (1 << 0) << '\n';
  cout << "1 << 1" << '\t' << (1 << 1) << '\n';
  cout << "0 << 0" << '\t' << (0 << 0) << '\n';
  cout << '\n';

  cout << "rightshift\n";
  cout << "0 >> 1" << '\t' << (0 >> 1) << '\n';
  cout << "1 >> 0" << '\t' << (1 >> 0) << '\n';
  cout << "1 >> 1" << '\t' << (1 >> 1) << '\n';
  cout << "0 >> 0" << '\t' << (0 >> 0) << '\n';
  cout << '\n';
}
