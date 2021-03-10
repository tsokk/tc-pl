#include <iostream>
#include <string>

void cipher(std::string &message, std::string &key) {
  int klen = key.size();
  int mlen = message.size();
  for (int i = 0; i < mlen; ++i) {
    wchar_t m = message[i];
    wchar_t k = key[i % klen];
    wchar_t e = m^k;
    std::wcout << e;
  }
  std::cout << '\n';
}

void ask_for(std::string &s, std::string msg) {
  std::cout << msg << '\n';
  getline(std::cin, s);
}

int main() {
  std::string msg;
  std::string key;
  ask_for(msg, "Enter message:");
  ask_for(key, "Enter key:");
  cipher(msg, key);
}
