#include <iostream>

using namespace std;
using UL = unsigned long;

void encode(UL *v, UL *k);
void decode(UL *v, UL *k);

// the tiny encryption algorithm
// https://web.archive.org/web/20190819094634/http://143.53.36.235:8080/tea.htm
int main() {
  // plaintext
  UL v[2]{0x12345678, 0x33333333};
  cout << "data to encrypt: " << v[0] << " " << v[1] << '\n';

  // key
  UL k[4]{0x00000000, 0x80000000, 0x80000000, 0x80000000};
  cout << "key: " << k[0] << " " << k[1] << " " << k[2] << " " << k[3] << '\n';

  // ciphertext
  UL w[2]{};

  encode(v, k);
  cout << "encrypted data: " << v[0] << " " << v[1] << '\n';

  decode(v, k);
  cout << "decrypted data: " << v[0] << " " << v[1] << '\n';
}

void encode(UL *v, UL *k) {
  UL x = v[0], y = v[1];
  UL a = k[0], b = k[1], c = k[2], d = k[3];
  UL sum = 0;
  UL delta = 0x9e3779b9, n = 32;
  while (n-- > 0) {
    sum += delta;
    x += (y << 4) + a ^ y + sum ^ (y >> 5) + b;
    y += (x << 4) + c ^ x + sum ^ (x >> 5) + d;
  }
  v[0] = x;
  v[1] = y;
}

void decode(UL *v, UL *k) {
  UL x = v[0], y = v[1];
  UL a = k[0], b = k[1], c = k[2], d = k[3];
  UL n = 32, sum, delta = 0x9e3779b9;
  sum = delta << 5;
  while (n-- > 0) {
    y -= (x << 4) + c ^ x + sum ^ (x >> 5) + d;
    x -= (y << 4) + a ^ y + sum ^ (y >> 5) + b;
    sum -= delta;
  }
  v[0] = x;
  v[1] = y;
}
