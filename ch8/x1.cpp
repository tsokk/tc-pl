#include  <iostream>

using namespace std;

struct Large {
	long double ld;
	double d;
	long l;
	int i;
	bool b;
	char c;
};

struct Small {
	double d;
	bool b;
	char c;
	int i;
	long l;
	long double ld;
};

int main()
{
	Small s = { };
	cout << sizeof(s) << '\n';      // size 48 (linux), size 32 (windows)

	Large l = {     };
	cout << sizeof(l) << '\n';      // size 48, size 40 (windows)
}

