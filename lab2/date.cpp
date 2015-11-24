#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"
#ifndef DATE_CPP
#define DATE_CPP
using namespace lab2;


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
    int cur = year();
    int ny = cur + y;
    if(isLeap(cur) && (month() > 2))
        this->julian_day_number--;
    for(int i = cur; i <= ny; i++) {
        if(isLeap(i))
            this->julian_day_number++;
    }
    this->julian_day_number += y*365;
};
void Date::add_month(int m) {
    while(m > 0) {
        if(isLeap(year())) {
            if(isLeap(year()) && month() == 2 && day() < 29)
                this->julian_day_number += 29;
            else if((day() == days_months[month()-1]) || day() > 29 && month() == 1) {
                this->julian_day_number += days_months[month()] + (days_months[month()] - days_months[month()-1]);
            }
            else
                this->julian_day_number += days_months[month()-1];
        }
        else if((day() == days_months[month()-1]) || day() > 28 && month() == 1) {
            this->julian_day_number += days_months[month()] + (days_months[month()] - days_months[month()-1]);
        }
        else
            this->julian_day_number += days_months[month()-1];
        m--;
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

int Date::mod_julian_day() const{

    return this->julian_day_number - 2400000.5;

}
#endif