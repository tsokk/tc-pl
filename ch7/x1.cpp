#include <iostream>

int main()
{
	// a pointer to a character
	char c = 'v';
	char* pc = &c;

	// an array of 10 integers
	int a[] { 1,2,3,4,5,6,7,8,910 };

	// a reference to an array of 10 integers
	int& b = *a;
	std::cout << ++b << '\n'; // writes 2

	// a pointer to an array of character strings
	char s[][4] = {
		"abc",
		"def"
	};
	char* ps = s[0];
	std::cout << *(ps+4)  << '\n';  // writes d

	// a pointer to a pointer  to  a  character
	char* ppc = pc;
	std::cout << *ppc << '\n'; // writes v

	//  a  constant  integer
	const int x = 0;

	//  a  pointer  to  a  constant  integer
	const int* px = &x;

	//  a  constant pointer to an integer
	int *const cp = &a[0];
}
