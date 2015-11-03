#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

namespace lab2 {
	class Date {
	public:
		//std::string * Months;
		int y;
		int m;
		int d;
		int Year();
		unsigned int Month();
		unsigned int Day();
		virtual unsigned int week_day() = 0;
		unsigned int days_per_week();
		virtual unsigned int days_this_month() = 0; //??
		virtual std::string week_day_name() = 0;
		virtual std::string month_name();
		virtual void add_year() = 0;
		virtual void add_month() = 0;
		int mod_julian_day ();
	};
}