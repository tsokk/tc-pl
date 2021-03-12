#include <iostream>

// error: #define PI = 3.141593;
// should read
#define PI 3.141593
// and it would be better to use a constant value
// or pi defined in <numbers> since C++20

// error: #define MAX(a,b) a>b?a:b
// should read
#define MAX(a,b) ((a > b) ? a : b)
// but note that one could also define a
// constexpr function for this

// error, it is recursive: #define fac(a) (a)*fac((a)-1)
// there may be some trickery around it (just use your
// favourite search engine), but I feel I do not want
// to know about it; at least not at this point

int main() {
  std::cout << PI << '\n';
  std::cout << MAX(2,3) << '\n';
  // std::cout << fac(6) << '\n';
}
