#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"
#ifndef JULIAN_HPP
#define JULIAN_HPP

namespace lab2 {
	class Julian : public Date {
		public:
                explicit Julian();
		std::string week_day_name() const;
		unsigned int week_day();
		unsigned int day() const;
		int year() const;
        	unsigned int month() const;
        	bool isLeap(int y);
        	Julian operator++(int);
        	Julian operator--(int);
                Julian& operator++();
                Julian& operator--();
                Date& operator=(const Date &src);
        	int convertToJDN(int J, int check) const;
        	double mod(int a, int b) const;
        	double div(double a, double b) const;
        	Julian(int Y, int M, int D);
        	Julian(Date const& src);
		};
}
#endif