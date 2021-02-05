void f(int a, int b) {
  if (a == 3) // (a = 3) => error: suggest parentheses around assignment used as
              // truth value [-Werror=parentheses]
    if ((a & 077) == 0) // (a & 077 == 0) => error: suggest parentheses around
                        // comparison in operand of '&' [-Werror=parentheses]
      a = b + 1;
}

void g(int a, int b) {
    a = b + 1; // a == b + 1 => error: statement has no effect [-Werror=unused-value]
    a = b + 2; // a + b = 2; => error: lvalue required as left operand of assignment
    b = a + b;  // b = a + &b; => error: invalid conversion from 'int*' to 'int' [-fpermissive]
}

int main() {}
