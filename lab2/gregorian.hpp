#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"


namespace lab2 {
    class Gregorian : Date {
       public:
        char week_day_name();
        static std::vector<std::string> v2; // declaration
        static std::vector<unsigned int> v3; // declaration
        unsigned int week_day();
        Gregorian operator++(int a);
		Gregorian operator--(int a);
        //Gregorian& operator=(const Gregorian &src);
      

        bool isLeap(int y);
        int Year() const;
        unsigned int Month() const;
        unsigned int Day() const;
    	private:
    		int convertToJDN(int J) const;
    		int mod(int a, int b) const;
    		int div(int a, int b) const;
    };
}