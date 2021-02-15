#include <iostream>

int main() {
  const int n = 1e9;
  double *p = new double[n];
  std::cout << n*sizeof(p) << '\n';
}

/*

When n = 1e9:
8000000000

real	0m0,004s
user	0m0,002s
sys	0m0,002s


When n = 1e10:
terminate called after throwing an instance of 'std::bad_alloc'
  what():  std::bad_alloc
/bin/bash: rivi 1:118023 Keskeytetty             (luotiin core-tiedosto)./a.out

real	0m0,185s
user	0m0,003s
sys	0m0,003s
*/
