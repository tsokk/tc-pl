#include <iostream>

double strlen(char *s) {
  double res = 0;
  while (*s != '\0') {
    ++s;
    ++res;
  }
  return res;
}

char *strcpy(char *dst, char *src) {
  const int n = strlen(src);
  for (int i = 0; i < n; ++i)
    dst[i] = src[i];
  dst[n] = '\0';
  return dst;
}

bool strcmp(char *a, char *b) {
  int len_a = strlen(a);
  int len_b = strlen(b);
  if (len_a != len_b)
    return false;
  for (int i = 0; i < len_a; ++i)
    if (a[i] != b[i])
      return false;
  return true;
}

int main() {
  char a[] = {"abc"};
  std::cout << strlen(a) << '\n';

  char b[4];
  strcpy(b, a);
  std::cout << b << '\n';
  
  std::cout << strcmp(a, b) << '\n';
  
  char d[] = {"def"};
  char e[] = {"ghi"};
  std::cout << strcmp(d, e) << '\n';
}
