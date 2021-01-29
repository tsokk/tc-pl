#include <iostream>

using namespace std;

void pswap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void rswap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 42;
	int b = 84;
	cout << "a is initially " << a << '\n';
	cout << "b is initially " << b << '\n';

	pswap(&a, &b);

	cout << "a is now " << a << '\n';
	cout << "b is now " << b << '\n';

	a = 42;
	b = 84;
	cout << "a is again " << a << '\n';
	cout << "b is again " << b << '\n';

	rswap(a, b);

	cout << "a is now " << a << '\n';
	cout << "b is now " << b << '\n';
}
