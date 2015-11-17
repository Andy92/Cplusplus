#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>
#ifndef DATE_HPP
#define DATE_HPP

namespace lab2 {
    class Date {
    public:
        static std::vector<std::string> v; // declaration
        static std::vector<int> v1; // declaration
        virtual bool isLeap(int y) = 0;
        int julian_day_number;
        virtual int year() const = 0;
        virtual unsigned int month() const = 0;
        virtual unsigned int day() const = 0;
        virtual unsigned int week_day() = 0;
        unsigned int days_per_week() const;
        unsigned int days_this_month() const;
        virtual std::string week_day_name() const = 0;
        std::string month_name() const;
        void add_year(int y);
        void add_month(int m);
        int mod_julian_day() const;
        Date& operator++();
        Date& operator--();
        Date& operator+=(int n);
        Date& operator-=(int n);
        virtual Date& operator=(const Date &src) = 0;
        int  operator-(const Date &src);
        bool operator<(const Date& src);
        bool operator>(const Date& src);
        bool operator==(const Date& src);
        bool operator<=(const Date& src);
        bool operator>=(const Date& src);
        bool operator!=(const Date& src);
        
        
        friend std::ostream& operator<<(std::ostream&, const Date&);

        
        
    };
           
}
#endif