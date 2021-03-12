#include <iostream>

double fac(int n) {
  double a = 1;
  switch (n) {
  case 0:
    break;
  case 1:
    break;
  default:
    while (n > 1) {
      a *= n;
      --n;
    }
  }
  return a;
}

int main() {
  for (int i = 0; i < 10; ++i)
    std::cout << i << "! = " << fac(i) << '\n';
}
