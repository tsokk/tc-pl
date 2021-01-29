#include <iostream>
#include <string>

int main()
{
	char str[] = "a short string";
	std::cout << sizeof(str) << '\n'; // 15

	std::string s {"a short string"};
	std::cout << s.size() << '\n'; // 14
}
