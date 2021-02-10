#include <iostream>

char * rev(char *s) {
  int len = 0;
  for (int i = 0; s[i] != '\0'; ++i)
    ++len;
  const int n = len;
  char *res = new char[n];
  for (auto i = 0; i < n; ++i) {
    res[i] = s[len-1];
    --len;
  }
  return res;
}

int main() {
  char s[] = {"abcdef"};
  std::cout << rev(s) << '\n';
}
