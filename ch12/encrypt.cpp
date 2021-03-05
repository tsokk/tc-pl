#include <iostream>
#include <string>

void cipher(std::string &message, std::string &key) {
  int klen = key.size();
  int mlen = message.size();
  for (int i = 0; i < mlen; ++i)
    std::cout << char(message[i] ^ key[i % klen]);
}

void ask_for(std::string &s, std::string msg) {
	std::cout << msg << '\n';
  getline(std::cin, s);
}

int main() {
  std::string plaintext;
	std::string key;
	ask_for(plaintext, "Enter plaintext:");
	ask_for(key, "Enter key:");
	cipher(plaintext, key);
}
