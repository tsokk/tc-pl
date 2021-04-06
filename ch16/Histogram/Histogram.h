#include <string>
#include <vector>

class Histogram
{
public:
	class Bad_value {};
	explicit Histogram(std::vector<int>& intervals, std::vector<int>& numbers);
	void draw();
private:
	size_t nlimits;
	int min;
	int max;
	std::vector<int>& ivals;
	std::vector<int>& nums;
	void compute();
};

