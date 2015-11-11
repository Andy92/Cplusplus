#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.cpp"
#include "date.hpp"


namespace lab2 {
    class Julian : Date {
       public:
        virtual std::string week_day_name();
        virtual unsigned int week_day();
        virtual Date& operator=(const Date &src);
        virtual Date& operator=(const Date &src);
        virtual bool operator<(const Date& src);
        virtual bool operator>(const Date& src);
        virtual bool operator==(const Date& src);
        virtual bool operator<=(const Date& src);
        virtual bool operator>=(const Date& src);
        virtual bool operator!=(const Date& src);
    };
}