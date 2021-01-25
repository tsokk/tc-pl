#include <iostream>

using namespace std;

void f(void) {}
enum class Answer { yes, no };
enum class Traffic_light { red, yellow, green };

int main()
{
	// sizes of fundamental types
	bool a {true};
	cout << "the size of bool is " << sizeof(a) << '\n';

	char z {'z'};
	cout << "the size of char is " << sizeof(z) << '\n';

	int b = 33;
	cout << "the size of int is " << sizeof(b) << '\n';

	long long c = 33;
	cout << "the size of long long is " << sizeof(c) << '\n';

	double d = 3.3;
	cout << "the size of double is " << sizeof(d) << '\n';
	long double e = 3.3;
	cout << "the size of long double is " << sizeof(e) << '\n';

	// sizeof cannot applied to void, which signifies absence of information
	// and therefore has no size

	char* q;
	cout << "the size of pointer to a character is " << sizeof(q) << '\n';

	double* r;
	cout << "the size of pointer to a double is " << sizeof(r) << '\n';

	long double* s;
	cout << "the size of pointer to a long double is " << sizeof(s) << '\n';

	cout << "the size of an enum class is " << sizeof(Answer::yes) << '\n';
	cout << "the size of another enum class is " << sizeof(Traffic_light::yellow) << '\n';
}
