#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// expected output: -4 -2 2 4
int main() {
  int a[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  vector<int> b;
  
  for (auto p = begin(a); p != end(a); ++p)
    if ((*p != 0) && (*p % 2 == 0))
      b.push_back(*p);

  for (const auto & i : b)
    cout << i << " ";
  cout << '\n';
}
