void send(int* to, int* from, int count)
// Duff ’s device. Helpful comment deliberately deleted.
{
  int n = (count + 7) / 8;
  switch (count % 8) {
  case 0:
    do {
      *to++ = *from++;
    case 7:
      *to++ = *from++;
    case 6:
      *to++ = *from++;
    case 5:
      *to++ = *from++;
    case 4:
      *to++ = *from++;
    case 3:
      *to++ = *from++;
    case 2:
      *to++ = *from++;
    case 1:
      *to++ = *from++;
    } while (--n > 0);
  }
}

/* What does the above example do?
 * Integer variable n gets the value count + 7 divided by 8. If (count + 7) is
 * not divisible by 8, the result gets truncated. If n modulo 8 is zero, it
 * increments addresses to and from by one, and then to gets the value of from.
 * This happens eight times, because of absence of break statements and
 * resulting fallthrough.
 *
 * Perhaps I really should verify that analysis using a debugger, but it is
 * horrible enough just to rewrite anyway, independent of its correctness. And
 * also adding back that comment stating its intent.
 */

int main() {}
