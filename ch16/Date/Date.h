#include <string>
#include <iostream>

namespace Chrono {
	enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	class Date {
	public:
		class Bad_date { };

		explicit Date(int dd = {}, Month mm = {}, int yy = {});

		int day() const;
		Month month() const;
		int year() const;

		std::string string_rep() const;

		Date& add_day(int n);
		Date& add_month(int n);
		Date& add_year(int n);
	private:
		bool is_valid();
		int d;
		Month m;
		int y;
	};

	bool is_date(int d, Month m, int y);
	bool is_leapyear(int y);

	bool operator==(Date a, Date b);
	bool operator!=(Date a, Date b);

	const Date& default_date();

	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& d);
}
