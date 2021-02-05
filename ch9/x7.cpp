#include <iostream>
#include <string>

using namespace std;

int main() {
  string in;
  for (string line; getline(cin, line);) {
    in += line;
    in += '\n';
  }
  string out;
  for (size_t i = 0; i != in.size(); ++i) {
    if (in[i] == '/' && in[i + 1] == '/') {
      while (in[i] != '\n')
        ++i;
    }
    if (in[i] == '/' && in[i + 1] == '*') {
      while (!(in[i] == '*' && in[i + 1] == '/'))
        ++i;
      i += 2;
    }
    out += in[i];
  }
  cout << out;
}
