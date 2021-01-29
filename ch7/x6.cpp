#include <iostream>

using namespace std;

struct Something {
	int a[3] { 1, 2, 3 };
};

int a[] { 1, 2, 3 };

int main()  // writes garbage and crashes
{
	int b[] { 1, 2, 3 };
	int* c = new int[3]{ 1, 2, 3 };

	// reading

	// global array - reading near beyond bounds
	cout << "reading global array of integers just after the end...\n";
	cout << a[3] << '\n';
	cout << "reading global array of integers just before the first element...\n";
	int* pa = a;
	--pa;
	cout << *pa << '\n';

	// global array - reading far beyond bounds
	cout << "reading global array of integers far after the end...\n";
	cout << a[100] << '\n';
	cout << "reading global array of integers far before the first element...\n";
	pa = pa - 100;
	cout << *pa << '\n';

	// local array - reading near beyond bounds
	cout << "reading local array of integers just after the end...\n";
	cout << b[3] << '\n';
	cout << "reading local array of integers just before the first element...\n";
	int* pb = b;
	--pb;
	cout << *pb << '\n';

	// local array - reading far beyond bounds
	cout << "reading local array of integers far after the end...\n";
	cout << b[100] << '\n';
	cout << "reading local array of integers far before the first element...\n";
	pb = pb - 100;
	cout << *pb << '\n';

	//  array allocated by new - reading near beyond bounds
	cout << "reading array of integers allocated by new just after the end...\n";
	cout << c[3] << '\n';
	cout << "reading  array of integers allocated by new just before the first element...\n";
	int* pc = c;
	--pc;
	cout << *pc << '\n';

	// array allocated by new - reading far beyond bounds
	cout << "reading array of integers allocated by new far after the end...\n";
	cout << c[100] << '\n';
	cout << "reading  array of integers allocated by new far before the first element...\n";
	pc = pc - 100;
	cout << *pc << '\n';

	// member array - reading near beyond bounds
	Something s = Something();
	cout << "reading member array of integers just after the end...\n";
	cout << s.a[3] << '\n';
	cout << "reading member array of integers just before the first element...\n";
	int* ps = s.a;
	--ps;
	cout << *ps << '\n';

	// array allocated by new - reading far beyond bounds
	cout << "reading member array of integers  far after the end...\n";
	cout << s.a[100] << '\n';
	cout << "reading member array of integers far before the first element...\n";
	ps = ps - 100;
	cout << *ps << '\n';

	// writing

	// global array - writing near beyond bounds
	cout << "writing global array of integers just after the end...\n";
	a[3] = 10;
	cout << "writing global array of integers just before the first element...\n";
	pa = a;
	--pa;
	*pa = 10;

	// global array - writing far beyond bounds
	cout << "writing global array of integers far after the end...\n";
	a[100] = 10;
	cout << "writing global array of integers far before the first element...\n";
	pa = pa - 100;
	*pa = 10;

	// local array - writing near beyond bounds
	cout << "writing local array of integers just after the end...\n";
	b[3] = 10;
	cout << "writing local array of integers just before the first element...\n";
	pb = b;
	--pb;
	*pb = 10;

	// local array - writing far beyond bounds
	cout << "writing local array of integers far after the end...\n";
	cout << b[100] << '\n';
	cout << "writing local array of integers far before the first element...\n";
	pb = pb - 100;
	*pb = 10;

	//  array allocated by new - writing near beyond bounds
	cout << "writing array of integers allocated by new just after the end...\n";
	cout << c[3] << '\n';
	cout << "writing  array of integers allocated by new just before the first element...\n";
	pc = c;
	--pc;
	*pc = 10;

	// array allocated by new - writing far beyond bounds
	cout << "writing array of integers allocated by new far after the end...\n";
	c[100] = 10;
	cout << "writing  array of integers allocated by new far before the first element...\n";
	pc = pc - 100;
	*pc = 10;

	// member array - writing near beyond bounds
	cout << "writing member array of integers just after the end...\n";
	s.a[3] = 10;
	cout << "writing member array of integers just before the first element...\n";
	ps = s.a;
	--ps;
	 *ps = 10;

	// array allocated by new - writing far beyond bounds
	cout << "writing member array of integers  far after the end...\n";
	s.a[100] = 10;
	cout << "writing member array of integers far before the first element...\n";
	ps = ps - 100;
	*ps = 10;

	delete c;
}
