#include <string>
#include <vector>

struct Date;
struct Date { int d, m, y; };

int day(Date*);
template<typename T> T abs(T);
template<typename T> T abs(T a) { return a<0 ? -a : a; }
int day(Date* p) { return p->d; }
double sqrt(double x) { return x*x; }

int main()
{
	char ch {'z'};
	std::string s {"adc"};
	int count;
	count = 1;
	double pi;
	pi = 3.14;
	int error_number = 0;

	const char* name;
	name = "Njal";
	const char* season[4];
	season[0] = "spring";
	season[1] = "summer";
	season[2] = "fall";
	season[3] =  "winter";
	std::vector<std::string> people;
	people = {name, "Skarpherdin", "Gunnar"};
}