#include <cmath>
#include <iostream>

// convert array of characters to corresponding integer
// assume that the characters are '0', '1', ... , '9'
int my_atoi(const char *p) {
  int len = 0;
  for (; *p != '\0'; ++p)
    ++len;
  p = p - len;

  double res = 0;
  char first = *p;
  char second = *(p + 1);
  if (first == '0' && (second == 'x' || second == 'X')) {
    // handle hexadecimal case
    p = p + 2;
    len -=  2;
    while (len > 0) {
      --len;
      res += (*p - '0') * std::pow(16, len);
      ++p;
    }
  } else if (first == '0') {
    //  handle octal case
    p = p + 1;
    len -=  1;
    while (len > 0) {
      --len;
      res += (*p - '0') * std::pow(8, len);
      ++p;
    }
  } else {
    // handle decimal case
    while (len > 0) {
      --len;
      res += (*p - '0') * std::pow(10, len);
      ++p;
    }
  }
  return res;
}

int main() {
  std::cout <<  "decimal '123' is decimal integer " << my_atoi("123") << '\n';
  std::cout <<  "octal '0123' is decimal integer " << my_atoi("0123") << '\n';
  std::cout <<  "hexadecimal '0x123' is decimal integer " << my_atoi("0x123") << '\n';
  std::cout <<  "hexadecimal '0X123' is decimal integer " << my_atoi("0X123") << '\n';

  /* Note that this exercise also asks to "Modify atoi() to handle the C++
   * character constant notation." I was unable to find the meaning of the
   * last three words of that sentence. Tried using the index of the book
   * and skimming the relevant chapter of the book. Perhaps something to
   * refactor later if the meaning clarifies.
   */
}
