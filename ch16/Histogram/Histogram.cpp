#include "Histogram.h"
#include <iostream>

Histogram::Histogram(std::vector<int>& intervals, std::vector<int>& numbers)
	: nlimits{ intervals.size() }, ivals{ intervals }, nums{ numbers }
{
	min = ivals[0];
	max = ivals[ivals.size() - 1];
}

void Histogram::draw()
{
	compute();
}

void Histogram::compute()
{

	for (int i = 1; i < nlimits; ++i) {

		// bucket lower and upper limits
		int lower = ivals[i - 1];
		int upper = ivals[i];

		// make label for bucket counts
		std::string lr = std::to_string(lower);
		std::string ur = std::to_string(upper);
		std::string lbl{ "[" + lr + ", " + ur + ")" };
		while (lbl.size() < 10) lbl += " ";
		
		// count values in this bucket
		int cnt = 0;
		for (const auto& n : nums) {
			if (min > n || n > max)
				throw Bad_value{};
			if (lower <= n && n < upper)
				++cnt;
		}

		// write out the label and the bar for this bucket
		std::cout << lbl << "\t";
		for (int i = 0; i < cnt; ++i)
			std::cout << '*';
		std::cout << '\n';
	}
}
