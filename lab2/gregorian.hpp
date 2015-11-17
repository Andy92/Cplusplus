#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"
#ifndef GREGORIAN_HPP
#define GREGORIAN_HPP

namespace lab2 {
    class Gregorian : public Date {
       public:
        std::string week_day_name() const;
        unsigned int week_day();
        Gregorian operator++(int);
		Gregorian operator--(int);
        //Gregorian& operator=(const Gregorian &src);
        Gregorian();
        Date& operator=(const Date &src);
        Gregorian(Gregorian const& src);
        Gregorian(int Y, int M, int D);
        bool isLeap(int y);
        int year() const;
        unsigned int month() const;
        unsigned int day() const;
    	private:
    		int convertToJDN(int J, int check) const;
    		int mod(int a, int b) const;
    		int div(int a, int b) const;
    };
}
#endif