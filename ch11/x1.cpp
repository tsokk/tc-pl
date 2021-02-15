#include <iostream>

void f(const int n) {
  double *p = new double[n];
  std::cout << n*sizeof(p) << '\n';
}

void g(const int n) {
  double *p = new double[n];
  for (int i = 0; i < n; ++i) {
    *p = 42;
    ++p;
  }
  std::cout << n*sizeof(p) << '\n';
}

int main() {
  // f(1e9);   8Gb, 0.001s
  // f(1e10);  std::bad_alloc, 0.164s
  // g(1e9);   päätetty, 7.779s
  // g(1e8);   ?, 0.005s
}
