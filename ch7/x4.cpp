#include <iostream>

int main()
{
	char s[] = "Yello";
	char* p = s;
	char* q = &s[4];
	std::cout << q-p << '\n';
}
