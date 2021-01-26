#include <iostream>
#include <limits>

using namespace std;

template<typename T>
void print()
{
	cout << sizeof(numeric_limits<T>::max())/sizeof(numeric_limits<char>::max())
		<< " characters\n";
}

int main()
{
	cout << "size of bool: " ;
	print<bool>();

	cout << "size of char: ";
	print<char>();

	cout << "size of short: ";
	print<short>();

	cout << "size of int: ";
	print<int>();

	cout << "size of  long: ";
	print<long>();

	cout << "size of long long: ";
	print<long long>();

	cout << "size of float: ";
	print<float>();

	cout << "size of double: ";
	print<double>();

	cout << "size of long double: ";
	print<long double>();

	cout << "size of unsigned: ";
	print<unsigned>();

	cout << "size of unsigned long: ";
	print<unsigned long>();
}

