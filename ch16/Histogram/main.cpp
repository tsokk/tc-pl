#include "Histogram.h"
#include "Rand_norm.h"
#include <iostream>

int main()
try {
	const int n = 200;
	std::vector<int> nums;
	Rand_norm rnd{ 15, 4 };
	for (int i = 0; i < n; ++i) nums.push_back(rnd());

	std::vector<int> ivals {0, 5, 10, 15, 20, 25, 30};
	Histogram h{ ivals, nums};
	h.draw();
}
catch (Histogram::Bad_value) {
	std::cerr << "out-of-range error" << '\n';
}