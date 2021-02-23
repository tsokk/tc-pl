#include <iostream>

void f(char*, int&);
using pf = void (*)(char*, int&);

pf f1;
void f2(pf f);
pf f3();

pf f4(pf f) { return f; }

int main() { }

