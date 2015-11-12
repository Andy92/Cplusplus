#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"

namespace lab2 {
	class Julian : Date {
		public:
			std::string week_day_name();
			unsigned int week_day();
			unsigned int Day() const;
			int Year() const;
        	unsigned int Month() const;
        	bool isLeap(int y);
        	Julian operator++(int);
        	Julian operator--(int);
        	int convertToJDN(int J, int check) const;
        	double mod(int a, int b) const;
        	double div(double a, double b) const;
        	Julian(int Y, int M, int D);
        	Julian(Julian const& src);
		};
}