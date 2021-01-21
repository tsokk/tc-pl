#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

int main()
	// g++ -O0 vs. g++ -O2 => 23 ms vs. 8 ms
{
	std::vector<int> a;
	auto t0 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i<=1000000; ++i) a.push_back(i);
	auto t1 = std::chrono::high_resolution_clock::now();
	double res = std::accumulate(a.begin(), a.end(), 0);
	std::cout << "result " << res << '\n';
	std::cout << "computed in " << std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
		<< " ms\n";
}

