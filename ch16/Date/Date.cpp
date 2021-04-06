#include "Date.h"

Chrono::Date::Date(int dd, Month mm, int yy)
	:d{ dd }, m{ mm }, y{ yy }
{
	if (y == 0) y = default_date().year();
	if (m == Month{}) m = default_date().month();
	if (d == 0) d = default_date().year();

	if (!is_valid()) throw Bad_date();
}

int Chrono::Date::day() const
{
	return d;
}

Chrono::Month Chrono::Date::month() const
{
	return m;
}

int Chrono::Date::year() const
{
	return y;
}

std::string Chrono::Date::string_rep() const
{
	return std::to_string(d) + "." + std::to_string(static_cast<int>(m)) + "." + std::to_string(y);
}

Chrono::Date& Chrono::Date::add_year(int n)
{
	y += n;
	return *this;
}

Chrono::Date& Chrono::Date::add_day(int n)
{
	// TODO: proper handling of adding days
	d += n;
	return *this;
}

Chrono::Date& Chrono::Date::add_month(int n)
{
	if (n == 0) return *this;

	if (n > 0) {
		int delta_y = n / 12;					// number of whole years
		int mm = static_cast<int>(m) + n % 12;	// number of months ahead
		if (12 < mm) {							// note: dec is represented by 12
			++delta_y;
			mm -= 12;
		}

		// ... handle the cases where the month mm doesn't have day d ...

		y += delta_y;
		m = static_cast<Month>(mm);

		// .. handle negative n ...

		return *this;
	}
}

bool Chrono::Date::is_valid()
{
	return is_date(d,m,y);
}

bool Chrono::is_date(int d, Chrono::Month m, int y)
{
	int ndays = 0;

	switch (m) {
	case Chrono::Month::feb:
		ndays += 28 + Chrono::is_leapyear(y);
		break;
	case Chrono::Month::apr: case Chrono::Month::jun: case Chrono::Month::sep: case Chrono::Month::nov:
		ndays = 30;
		break;
	case Chrono::Month::jan: case Chrono::Month::mar: case Chrono::Month::may: case Chrono::Month::jul:
	case Chrono::Month::aug: case Chrono::Month::oct: case Chrono::Month::dec:
		ndays = 31;
		break;
	default:
		return false;
	}

	return 1 <= d && d <= ndays;
}

bool Chrono::is_leapyear(int y)
{
	// year which is an integer multiple of 4 (except for years evenly divisible by 100, 
	// which are not leap years unless evenly divisible by 400)
	bool leap = false;
	if (y % 4 != 0) leap = false;
	else if (y % 100 != 0) leap = true;
	else if (y % 400 != 0) leap = false;
	else leap = true;
	return leap;
}

inline bool Chrono::operator==(Date a, Date b)
{
	return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
}

bool Chrono::operator!=(Date a, Date b)
{
	return a.day() != b.day() || a.month() != b.month() || a.year() != b.year();
}

const Chrono::Date& Chrono::default_date()
{
	static Chrono::Date d{ 1, Chrono::Month::jan, 1970 };
	return d;
}

std::ostream& Chrono::operator<<(std::ostream& os, const Chrono::Date& d)
{
	return os << d.string_rep();
}

std::istream& Chrono::operator>>(std::istream& is, Date& d)
{
	int day;
	is >> day;

	int m;
	is >> m;

	int y;
	is >> y;

	d = Chrono::Date(day, static_cast<Chrono::Month>(m), y);
	return is;
}
