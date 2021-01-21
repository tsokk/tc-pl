#include <iostream>
#include <iomanip>
#include <map>
#include <random>
#include <string>

using namespace std;

class Rand_norm {
public:
	Rand_norm(double mean, double sd) :dist{mean, sd} { }
	int operator()() { return dist(re); }
private:
	default_random_engine re;
	normal_distribution<> dist;	
};

int main()
{
	Rand_norm rnd {15, 5};
	
	map<int,int> hist;
	for (int i = 0; i<10000; ++i)
		++hist[round(rnd())];
	
	for (auto i = 0; i<30; ++i)
		cout << hist.find(i)->first << '\t'
			<< string(hist.find(i)->second/15, '*')
			<< '\n';
}
