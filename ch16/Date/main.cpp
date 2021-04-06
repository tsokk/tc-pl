#include "Date.h"

int main() {
	Chrono::Date today{ 28, Chrono::Month::feb, 2024 };
	Chrono::Date a_date{ 26, Chrono::Month::mar };
	Chrono::Date another_date{ 26 };
	today.add_day(1);
}