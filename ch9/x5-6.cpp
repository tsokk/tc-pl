#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string itoa1(int i, char b[]) {
  div_t dv{};
  dv.quot = i;
  string buf;
  do {
    dv = div(dv.quot, 10);
    buf += b[abs(dv.rem)];
  } while (dv.quot);
  if (i < 0)
    buf += '-';
  return {buf.rbegin(), buf.rend()};
}

string itoa2(int i, char b[], int len) {
  div_t dv{};
  dv.quot = i;
  string buf;
  for (int i = 1; i <= len; ++i) {
    dv = div(dv.quot, 10);
    buf += b[abs(dv.rem)];
  }
  if (i < 0)
    buf += '-';
  return {buf.rbegin(), buf.rend()};
}

int main() {
  char b[] = "0123456789";
  string res1 = itoa1(123, b);
  cout << "string representation of 123 is " << res1 << '\n';
  string res2 = itoa2(456, b, 3);
  cout << "string representation of 456 is " << res2 << '\n';
}
