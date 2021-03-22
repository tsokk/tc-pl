#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <stdexcept>

using namespace std;

FILE *eopen(const char *filename, const char *mode) {
  FILE *fp = fopen(filename, mode);
  if (!fp)
    throw runtime_error("eopen: can't open file");
  else
    return fp;
}

int eclose(FILE *stream) {
  int ret_val = fclose(stream);
  if (ret_val != 0)
    throw runtime_error("eclose: can't close file");
  else
    return ret_val;
}

int main()
try {
  FILE *fp = eopen("test.txt", "r");
  eclose(fp);
} catch (exception &e) {
  cout << e.what() << '\n';
}