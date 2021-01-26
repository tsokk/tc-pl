#include <iostream>

using namespace std;

void print(char start, char end)
{
	cout << "characters:\n";
	char c = start;
	while (c<=end) {
		cout << c << " ";
		++c;
	}
	cout << '\n';

	cout << "their integer values (decimal):\n";
	int i = start;
	while (i<=end) {
		cout << dec << i << " ";
		++i;
	}
	cout << '\n';

	cout << "their integer values (hexadecimal):\n";
	int j = start;
	while (j<=end) {
		cout << hex << j << " ";
		++j;
	}
	cout << "\n\n";
}

int main()
{
	print('a','z');
	print('0','9');
	print(33,126);
}
