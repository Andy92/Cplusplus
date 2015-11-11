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
        virtual bool isLeap(int y) = 0;
        int julian_day_number;
        virtual int Year() const = 0;
        virtual unsigned int Month() const = 0;
        virtual unsigned int Day() const = 0;
        virtual unsigned int week_day() = 0;
        unsigned int days_per_week();
        unsigned int days_this_month();
        virtual char week_day_name() = 0;
        std::string month_name();
        void add_year(int y);
        void add_month(int m);
        int mod_julian_day();
        Date& operator++();
        Date& operator--();
        Date& operator+=(int n);
        Date& operator-=(int n);
        Date& operator=(const Date &src);
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
