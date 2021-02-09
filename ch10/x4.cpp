#include <iostream>
using namespace std;

// underflow
void f0() {
  int i = -1;
  while (i < 0)
    --i;
  cout << "i has become positive!" << i << '\n';
}

// overflow
void f1() {
  int i = 1;
  while (0 < i)
    ++i;
  cout << "i has become negative!" << i << '\n';
}

// division by zero
void f2() {
  int i = 0;
  cout << "division by zero!" << (2 / i) << '\n';
}

// do not assume functions are evaluated left-to-right
int f3(int *x) {
  *x -= 10;
  return *x;
}

int f4(int *x) {
  *x *= 10;
  return *x;
}

// read and write an object
void f5() {
  int a[] = {1, 2};
  int i = 1;
  a[i] = i++;
  cout << a[i] << '\n';
}

int main() {
  // Test five kinds of undefined behaviour
  /*
  f0();
  $ g++ -Wall x4.cpp
  $ ./a.out
  i has become positive!2147483647
  $ clang++ -Wall x4.cpp
  $ ./a.out
  i has become positive!2147483647
  */
  /*
  f1();
  $ g++ -Wall x4.cpp
  $ ./a.out
  i has become negative!-2147483648
  $ clang++ -Wall x4.cpp
  $ ./a.out
  i has become negative!-2147483648
  */
  /*
  f2();
  $ g++ -Wall x4.cpp
  $ ./a.out
  Liukulukupoikkeus (luotiin core-tiedosto)
  $ clang++ -Wall x4.cpp
  $ ./a.out
  Liukulukupoikkeus (luotiin core-tiedosto)
  */
  /*
  int x = 5;
  int y = f3(&x) + f4(&x);
  cout << y << '\n';
  $ g++ -Wall x4.cpp
  $ ./a.out
  -55
  $ clang++ -Wall x4.cpp
  $ ./a.out
  -55
  */
  /*
  f5();
  $ g++ -Wall x4.cpp
  x4.cpp: Funktio ”void f5()”:
  x4.cpp:41:11: varoitus: operaatio ”i”:lle voi olla määrittelemätön [-Wsequence-point]
    41 |   a[i] = i++;
        |          ~^~
  x4.cpp:41:11: varoitus: operaatio ”i”:lle voi olla määrittelemätön [-Wsequence-point]
  $ clang++ -Wall x4.cpp
  x4.cpp:41:11: warning: unsequenced modification and access to 'i' [-Wunsequenced]
    a[i] = i++;
      ~     ^
  1 warning generated.
  */
}
