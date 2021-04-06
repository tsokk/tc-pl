#include "Rand_norm.h"

Rand_norm::Rand_norm(double mean, double sd)
	:dist{ mean, sd } { }

int Rand_norm::operator()()
{
	return dist(re);
}
