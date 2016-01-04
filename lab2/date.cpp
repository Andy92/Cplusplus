#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"
namespace lab2 {


const char *Months[] = {
            "Januari",
            "Febuary",
            "Mars",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
        };
std::vector<std::string> Date::v(Months, Months+12); // definition

const int days_months[] = {
            31,
            28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31
        };
std::vector<int> Date::v1(days_months, days_months+12); // definition

void Date::add_year(int y) {
    if(y>0){ 
        int cur = year();
        int ny = cur + y;
        if(isLeap(cur) && (month() > 2))
            this->julian_day_number--;
        for(int i = cur; i <= ny; i++) {
            if(isLeap(i))
                this->julian_day_number++;
        }
        this->julian_day_number += y*365;
    } else {

        int cur = year();
        int ny = cur + y;
        if(isLeap(ny) && (month() > 2))
            this->julian_day_number++;
        for(int i = ny; i < cur; i++) {
            if(isLeap(i))
                this->julian_day_number--;
        }
        this->julian_day_number += y*365;
        }

}
void Date::add_month(int m) {
    while(m > 0) {
        if(isLeap(year())) {            // if leap year
            //std::cout << "leap year" << std::endl;
            if(isLeap(year()) && month() == 2 && day() <= 29)    // if it's feb and day is under 29
                this->julian_day_number += 29;
            else if(day() > 29 && month() == 1) {
                int tmp = day();
                this->julian_day_number += days_months[month()]+1 - (days_months[month()]+1 - day());
                if (m>1) {
                    this->julian_day_number += tmp;
                    m--;
                }
            }
            else
                this->julian_day_number += days_months[month()-1];
        }
        else if(day() > 28 && month() == 1) {
            int tmp = day();
            this->julian_day_number += days_months[month()] - (days_months[month()] - day());
            if (m>1) {
                this->julian_day_number += tmp;
                m--;
            }
        }   
        else
            this->julian_day_number += days_months[month()-1];
        m--;
    }
    while(m < 0) {
        int lastmon = 0;
        if(month()>1){
            lastmon = month()-2;
        } else if (month()==1){
            lastmon = 11;
        } else {
            lastmon = 10;
        }

        if(isLeap(year())) {
            if(isLeap(year()) && month() == 3 && day() <= 29)
                this->julian_day_number -= 29;
            else if(day() > 29 && month() == 2) {
                int tmp = day();
                this->julian_day_number -= days_months[month()-1]+1 - (days_months[month()-1]+1 - day());
                if (m<(-1)) {
                    this->julian_day_number -= tmp;
                    m++;
                }
            }
            else
                this->julian_day_number -= days_months[lastmon];
        }
        else if(day() > 28 && month() == 2) {
            int tmp = day();
            this->julian_day_number -= days_months[month()-1] - (days_months[month()-1] - day());
            if (m<(-1)) {
                this->julian_day_number -= tmp;
                m++;
            }
        }
        else
            this->julian_day_number -= days_months[lastmon];
        m++;
    }
}
unsigned int Date::days_this_month() const {
    return days_months[month() - 1];
}
unsigned int Date::days_per_week () const{
    return 7;
}
std::string Date::month_name() const{
    //return Date::Months[month-1];
   return Months[month()-1];
}
Date& Date::operator+=(int n) {
    this->julian_day_number += n;
    return *this;
}
Date& Date::operator-=(int n) {
   this->julian_day_number -= n;
    return *this;
}

int Date::operator-(const Date &src) const {
    return this->julian_day_number - src.julian_day_number;
}
//relationalops


bool Date::operator<(const Date& src) const {
    if(this->julian_day_number < src.julian_day_number)
        return true;
    return false;
}
bool Date::operator>(const Date& src) const {
    if(this->julian_day_number > src.julian_day_number)
        return true;
    return false;
}
bool Date::operator==(const Date& src) const {
    if(this->julian_day_number == src.julian_day_number)
        return true;
    return false;
}
bool Date::operator<=(const Date& src) const {
    if(this->julian_day_number <= src.julian_day_number)
        return true;
    return false;
}
bool Date::operator>=(const Date& src) const {
    if(this->julian_day_number >= src.julian_day_number)
        return true;
    return false;
}
bool Date::operator!=(const Date& src) const {
    if(this->julian_day_number != src.julian_day_number)
        return true;
    return false;
}
std::ostream& operator<<(std::ostream& out, Date const& obj) {
    out << obj.year() << "-" << obj.month() << "-" << obj.day();
    return out;
}
int Date::mod_julian_day() const{

    return this->julian_day_number - 2400000.5;
}
}