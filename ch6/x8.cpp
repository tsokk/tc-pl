#include <iostream>
#include <limits>

using namespace std;

template<typename T>
void print()
{
	cout << "min:  ";
	cout << numeric_limits<T>::min() << '\n';
	cout << "max: ";
	cout <<  numeric_limits<T>::max() << "\n\n";
}

int main()
{
	cout << "bool\n" ;
	print<bool>();
	cout << "char\n";
	print<char>();
	cout << "short\n";
	print<short>();
	cout << "int\n";
	print<int>();
	cout << "long\n";
	print<long>();
	cout << "long long\n";
	print<long long>();
	cout << "float\n";
	print<float>();
	cout << "double\n";
	print<double>();
	cout << "long double\n";
	print<long double>();
	cout << "unsigned\n";
	print<unsigned>();
	cout << "unsigned long\n";
	print<unsigned long>();
}

