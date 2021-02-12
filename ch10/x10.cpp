#include <iostream>
#include <memory>

std::unique_ptr<char[]> rev(char *s) {
  int len = 0;
  for (int i = 0; s[i] != '\0'; ++i)
    ++len;
  const int n = len;
  std::unique_ptr<char[]> res {new char[n]};
  for (auto i = 0; i < n; ++i) {
    res[i] = s[len-1];
    --len;
  }
  return res;
}

int main() {
  char s[] = {"abcdef"};
  rev(s);
}
