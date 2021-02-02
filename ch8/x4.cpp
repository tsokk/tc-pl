#include <iostream>
#include <string>

using namespace std;

struct Date {
	int day;
	string month;
	int year;

	Date(int d, const string& m, int y);
};

Date::Date(int d, const string& m, int y)
	:day{d}, month{m}, year{y} { }

void print(Date d)
{
	cout << d.month << " " << d.day << ", " << d.year << '\n';
}

Date read(istream& is)
{
	int day;
	string month;
	int year;
	
	is >> day >> month >> year;
	
	return {day, month, year};
}

int main()
{
	Date dt {12, "January", 1962};
	print(dt);

	cout << "enter another date (day month year): ";
	Date ds = read(cin);
	print(ds);
}
