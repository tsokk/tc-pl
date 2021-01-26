#include <iostream>
#include <limits>

using namespace std;

template<typename T>
void print()
{
	cout << alignof(T) << '\n';
}

int main()
{
	cout << "alignment of bool: " ;
	print<bool>();

	cout << "alignment of char: ";
	print<char>();

	cout << "alignment of short: ";
	print<short>();

	cout << "alignment of int: ";
	print<int>();

	cout << "alignment of  long: ";
	print<long>();

	cout << "alignment of long long: ";
	print<long long>();

	cout << "alignment of float: ";
	print<float>();

	cout << "alignment of double: ";
	print<double>();

	cout << "alignment of long double: ";
	print<long double>();

	cout << "alignment of unsigned: ";
	print<unsigned>();

	cout << "alignment of unsigned long: ";
	print<unsigned long>();
}

