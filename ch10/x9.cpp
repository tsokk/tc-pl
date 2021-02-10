#include <iostream>
#include <cstring>

char * cat(char *s1, char *s2) {
  const int n1 = strlen(s1);
  const int n2 = strlen(s2);
  const int n = n1 + n2;
  char *res = new char[n];
  for (auto i = 0; i < n1; ++i)
    res[i] = s1[i];
  for (auto i = n1; i < n1 + n2; ++i)
    res[i] = s2[i - n1];
  return res;
}

int main() {
  char s1[] = {"abc"};
  char s2[] = {"def"};
  std::cout << cat(s1, s2) << '\n';
}
