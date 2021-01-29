#include <iostream>
#include <string>

using namespace std;

void print(const auto& m)
	// auto in parameter declaration is valid in C++20
	// compile with g++ -fconcepts-ts
{
	for (const auto& i : m)
		cout << i << " ";
	cout << '\n';
}

int main()
{
	string month[] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	for (const auto& m : month)
		cout << m << " ";
	cout << '\n';

	print(month);
}
