
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

std::string Gregorian::week_day_name() {
    return v2[(this->julian_day_number % 7)];
}

unsigned int Gregorian::week_day() {
    return (this->julian_day_number % 7 + 1);
}

Gregorian::Gregorian(int Y, int M, int D) {
    this->julian_day_number = D + (153*M + 2)/5 + 365*Y + Y/4 - Y/100 + Y/400 - 32045;
}
Gregorian::Gregorian(Gregorian const& src) {
    this->julian_day_number = src.julian_day_number;
}

Gregorian Gregorian::operator++(int a) {
    Gregorian tmp = *this;
    this->julian_day_number++;
    return tmp;
}
Gregorian Gregorian::operator--(int a) {
    Gregorian tmp = *this;
    this->julian_day_number--;
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
	int y = convertToJDN(this->julian_day_number, 2);
    return y;
}
unsigned int Gregorian::Month() const{
	int m = convertToJDN(this->julian_day_number, 1);
    return m;

}
unsigned int Gregorian::Day() const {
	int d = convertToJDN(this->julian_day_number, 0);
    return d;

}

// Convert to gregorian from JDN
    int Gregorian::convertToJDN(int J, int check) const {
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
    if(check == 0)
        return D;
    if(check == 1)
        return M;
    if(check == 2)
        return Y;
    return 0;
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
int main() {
}