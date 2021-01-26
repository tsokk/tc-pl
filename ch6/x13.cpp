#include <iostream>
#include <unordered_set>

int main()
{
	std::unordered_set<int> si {4,5,9,17,12};
	for (const auto& i : si)
		std::cout << i << '\n';
}
