
#include "gregorian.hpp"

using namespace lab2;

const char *week_day_name[] = {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
        };
std::vector<std::string> v2(week_day_name, week_day_name+7); // definition
        
unsigned int week_day[] {
            0,
            1,
            2,
            3,
            4,
            5,
            6,
        };
       
std::vector<unsigned int> v3(week_day, week_day+7); // definition

Gregorian Gregorian::operator++(int a) {
    Gregorian tmp = *this;
    ++*this;
    return tmp;
}
Gregorian Gregorian::operator--(int a) {
    Gregorian tmp = *this;
    --*this;
    return tmp;
}
bool Gregorian::isLeap(int year) {
	int req1 = year % 100;
	int req2 = year % 400;
	if ((req1 + req2) == 0) {
		return true;
	}
	return false;
}


int Gregorian::Year() const {
	int Y,M,D = convertToJDN(this->julian_day_number);
	return Y;
}
unsigned int Gregorian::Month() const{
	int Y,M,D = convertToJDN(this->julian_day_number);
	return M;

}
unsigned int Gregorian::Day() const {
	int Y,M,D = convertToJDN(this->julian_day_number);
	return D;

}

// Convert to gregorian from JDN
    int Gregorian::convertToJDN(int J) const {
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
    int f = J + j + (((4 * J + B) / 146097) * 3) / 4 + C;
    // beräkna resten
    int e = r * f + v;
    int g = mod(e,p) / r;
    int h = u * g + w;
    int D = (mod(h,s)) / u + 1;
    int M = mod(h / s + m1,n) + 1;
    int Y = div(e,p) - y1 + (n + m1 - M) / n;
    return Y,M,D;
}			

// modulus
int Gregorian::mod(int a, int b) const {
    int r = a % b;
    return r;
}

// Integer division
int Gregorian::div(int a, int b) const {
    int r = a / b;
    return r;
}
