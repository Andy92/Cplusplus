#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"

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
    int cur = Year();
    int ny = cur + y;
    if(isLeap(cur) && (Month() > 2))
        this->julian_day_number--;
    for(int i = cur; i <= ny; i++) {
        if(isLeap(i))
            this->julian_day_number++;
    }
    this->julian_day_number += y*365;
};
void Date::add_month(int m) {
    while(m > 0) {
        if(isLeap(Year())) {
            if(isLeap(Year()) && Month() == 2 && Day() < 29)
                julian_day_number += 29;
            else if((Day() == days_months[Month()-1]) || Day() > 29 && Month() == 1) {
                julian_day_number += days_months[Month()] + (days_months[Month()] - days_months[Month()-1]);
            }
            else
                julian_day_number += days_months[Month()-1];
        }
        else if((Day() == days_months[Month()-1]) || Day() > 28 && Month() == 1) {
            julian_day_number += days_months[Month()] + (days_months[Month()] - days_months[Month()-1]);
        }
        else
            julian_day_number += days_months[Month()-1];
        m--;
    }
}

unsigned int Date::days_per_week () {
    return 7;
}
std::string Date::month_name() {
    //return Date::Months[Month-1];
   return Months[Month()-1];
}
Date& Date::operator++() {
    this->julian_day_number++;
    return *this;
}
Date& Date::operator--() {
    this->julian_day_number--;
    return *this;
}
Date& Date::operator+=(int n) {
    this->julian_day_number += n;
    return *this;
}
Date& Date::operator-=(int n) {
   this->julian_day_number -= n;
    return *this;
}
Date& Date::operator=(const Date &src) {
    this->julian_day_number = src.julian_day_number;
    return *this;
}

int Date::operator-(const Date &src) {
    return this->julian_day_number - src.julian_day_number;
    
}
//relationalops


bool Date::operator<(const Date& src) {
    if(this->julian_day_number < src.julian_day_number)
        return true;
    return false;
}
bool Date::operator>(const Date& src) {
    if(this->julian_day_number > src.julian_day_number)
        return true;
    return false;
}
bool Date::operator==(const Date& src) {
    if(this->julian_day_number == src.julian_day_number)
        return true;
    return false;
}
bool Date::operator<=(const Date& src) {
    if(this->julian_day_number <= src.julian_day_number)
        return true;
    return false;
}
bool Date::operator>=(const Date& src) {
    if(this->julian_day_number >= src.julian_day_number)
        return true;
    return false;
}
bool Date::operator!=(const Date& src) {
    if(this->julian_day_number != src.julian_day_number)
        return true;
    return false;
}


int Date::mod_julian_day() {

    return this->julian_day_number - 2400000.5;

}


std::ostream& operator<<(std::ostream& out, const Date& obj) {
    out << obj.Year() <<  "-" << obj.Month() <<  "-" << obj.Day();
    return out;
}
int main () {
}

