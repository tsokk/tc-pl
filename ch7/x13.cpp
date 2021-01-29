#include <iostream>

void use(char c) {
	std::cout << c;
}

void fi(char v[])
{
	for (int i = 0; v[i]!=0; i++)
		use(v[i]);
}

void fp(char v[])
{
	for (char* p = v; *p!=0; ++p)
		use(*p);
}

int main()
{
	char v[] = "asdf";
	fi(v);
	fp(v);
}
