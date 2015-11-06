#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>

namespace lab2 {
	class Date {
	public:
		static std::vector<std::string> v; // declaration
		static std::vector<int> v1; // declaration
		static std::vector<std::string> v2; // declaration
		static std::vector<std::string> v3; // declaration

		int y;
		int m;
		int d;
		int Year();
		unsigned int Month();
		unsigned int Day();
		virtual unsigned int week_day() = 0;
		unsigned int days_per_week();
		unsigned int days_this_month(); //??
		virtual std::string week_day_name() = 0;
		virtual std::string month_name();
		virtual void add_year() = 0;
		virtual void add_month() = 0;
		int mod_julian_day ();
		Date& operator++();
		Date& operator--();
		Date& operator+=(int n);
	};
}