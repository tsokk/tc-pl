#include <limits>
#include <iostream>

int main()
{
	if (std::numeric_limits<char>::is_signed)
		std::cout << "signed\n";
	else
		std::cout << "unsigned\n";
}
