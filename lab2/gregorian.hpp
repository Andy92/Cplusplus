#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"


namespace lab2 {
    class Gregorian : Date {
       public:
        std::string week_day_name();
        unsigned int week_day();
        Gregorian operator++(int a);
		Gregorian operator--(int a);
        //Gregorian& operator=(const Gregorian &src);
        Gregorian(Gregorian const& src);
        Gregorian(int Y, int M, int D);
        bool isLeap(int y);
        int Year() const;
        unsigned int Month() const;
        unsigned int Day() const;
    	private:
    		int convertToJDN(int J, int check) const;
    		int mod(int a, int b) const;
    		int div(int a, int b) const;
    };
}