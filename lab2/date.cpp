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

const char *weekday[] = {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
        };

std::vector<std::string> Date::v2(weekday, weekday+7); // definition


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

/*
std::ostream& operator<<(std::ostream &out, const Date &obj) {
    out << obj.y <<  "-" << obj.m <<  "-" <<obj.d;
    return out;
}
*/
int Date::mod_julian_day() {

    return this->julian_day_number - 2400000.5;

}
/*
// Convert to julian or gregorian from JDN
private int Date::convert(const Date *date) {
        // Parameters for Greg:
        int y1 = 4716;
        int j = 1401;
        int m1 = 2;
        int n = 12;
        int r = 4;
        int p = 1461;
        int v = 3;
        int u = 5;
        int s = 153;
        int w = 2;
        int B = 274277;
        int C = -38;
        // End of parameters

        int f = 0;
        if (date == Julian) {
            // beräkna f för Julian
            f = J +j;
        } else {
            // beräkna f för greg
            f = J + j + (((4 * J + B) / 146097) * 3) / 4 + C;
        }
        
    
        // beräkna resten för båda.
        int e = r * f + v;
        int g = mod(e,p) / r;
        int h = u * g + w;
        int D = (mod(h,s)) / u + 1;
        int M = mod(h / s + m1,n) + 1;
        int Y = (e div p) - y1 + (n + m1 - M) / n;
}
*/
int main () {
}