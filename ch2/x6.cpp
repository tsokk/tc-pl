#include <iostream>
#include <string>

int main()
{
	std::cout << "type in a bool (that is, 'true or false'), an int, a char, a double, and a string (separated by spaces): ";
	bool a;
	std::cin >> a;

	char b;
	std::cin >> b;

	int c;
	std::cin >> c;

	double d;
	std::cin >> d;

	std::string e;
	std::cin >> e;

	std::cout << "you entered:\n" << a << " " << b << " " << c << " " << d << " " << e
		<< '\n';
}
