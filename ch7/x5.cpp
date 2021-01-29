#include <iostream>

int main()
{
	int a[] { 1,2,3,4,5,6};
	int* p = a;
	int* q = &a[4];
	std::cout << q-p << '\n';
}
