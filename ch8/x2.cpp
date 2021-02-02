#include <iostream>

using namespace std;

void tbl1()
{
        char month[][12] = {
                "January",
                "February",
                "March",
                "April",
                "May",
                "June",
                "July",
                "August",
                "September",
                "October",
                "November",
                "December"
        };

        int day[] = {
                31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
        };

        for (int i=0; i<12; ++i)
		cout << month[i] << " " << day[i] << '\n';
}

struct Month {
	char name[12];
	int days;
};

void tbl2()
{
        Month m[] = {
                {"January", 31},
                {"February", 28},
                {"March", 31},
                {"April", 30},
                {"May", 31},
                {"June", 30},
                {"July", 31},
                {"August", 31},
                {"September", 30},
                {"October", 31},
                {"November", 30},
                {"December", 31}
        };

        for (int i=0; i<12; ++i)
		cout << m[i].name << " " << m[i].days << '\n';
}

int main()
{
	tbl1();
	cout << '\n';
	tbl2();
}

