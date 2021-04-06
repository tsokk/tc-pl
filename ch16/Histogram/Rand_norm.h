#include <map>
#include <random>
#include <string>

class Rand_norm {
public:
    Rand_norm(double mean, double sd);
    int operator()();
private:
    std::default_random_engine re;
    std::normal_distribution<> dist;
};
