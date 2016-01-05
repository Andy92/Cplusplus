#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"
namespace lab2 {


const char *Months[] = {
            "January",
            "February",
            "March",
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
    int a = (month() > 2) ? 1:0;
    int b = (month() <= 2) ? 1:0;
    if(y>0){
        int cur = year();
        int ny = cur + y;
        for(int i = cur+a; i < ny+a; ++i) {
            if(isLeap(i))
                this->julian_day_number++;
        }
        this->julian_day_number += y*365;
    } else {
        int cur = year();
        int ny = cur + y; // 2032
        for(int i = cur-b; i > ny-b; i--) {
            if(isLeap(i)) {
                this->julian_day_number--;
            }
        }
        this->julian_day_number += y*365;
        }
}
void Date::add_month(int m) {
    
    int tmpday = day();
    int dag = tmpday;
    if (dag > 28) {
        this->julian_day_number -= tmpday - 28;
        dag = 28;
    }
    if(m>0) {
        while(m > 0) {
            if(isLeap(year()) && month() == 2){    // if it's feb and day is under 29
                this->julian_day_number += 29;
            } else {
                    this->julian_day_number += days_months[month()-1];
            }
            m--;
        }
        int b = ((month() == 2) && isLeap(year())) ? 1:0;
        if((days_months[month()-1] + b) > tmpday) {
            this->julian_day_number += tmpday - dag;
        } else {
            this->julian_day_number += days_months[month()-1]+b - 28;
        }
    }
    if(m<0) {
        while(m < 0) {
            int lastmon = 0;
            if(month()>1){
                lastmon = month()-2;
            } else if (month()==1){
                lastmon = 11;
            } else {
                lastmon = 10;
            }
            if(isLeap(year()) && month() == 3)    // if it's feb and day is under 29
                this->julian_day_number -= 29;
            else {
                    this->julian_day_number -= days_months[lastmon];
            }
            m++;
        }
        int b = ((month() == 2) && isLeap(year())) ? 1:0;
        if((days_months[month()-1] + b) > tmpday) {
            this->julian_day_number += tmpday - dag;
        } else {
            this->julian_day_number += days_months[month()-1]+b - 28;
        }
    }
}
unsigned int Date::days_this_month() const {
    if ((isLeap(year())) && (month() == 2)) {
        return days_months[month() - 1]+1; 
    }
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