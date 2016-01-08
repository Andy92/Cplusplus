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

std::string Gregorian::week_day_name() const{
    return v2[((int)this->julian_day_number % 7)];
}

unsigned int Gregorian::week_day() const {
    int i = this->julian_day_number;
    return (i % 7) + 1;
}

Gregorian::Gregorian() {
     time_t now;
    //  time_t now = time(0);
    k_time(&now);
    
    //std::cout << now << std::endl;
    this->julian_day_number = 2440588 + (now / 86400);
    validDate(year(), month(), day());
}


Gregorian::Gregorian(int Y, int M, int D) {
    validDate(Y, M, D);
    int a = (14-M)/12;
    int m = M + 12*a -3;
    int y = Y + 4800 - a;
    int d = D;
    this->julian_day_number = d + (153*m + 2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
}

void Gregorian::validDate(int Y, int M, int D) const {
    if(!isLeap(Y) && M == 2 && D == 29)
        throw std::invalid_argument("invalid date");
    if(Y > 2558 || Y < 1858)
        throw std::invalid_argument("invalid date");
    if((M <= 0 || M > 12) || (D <= 0 ||D > 31))
        throw std::invalid_argument("invalid date");
}


Gregorian::Gregorian(Date const& src) {
    this->julian_day_number = src.julian_day_number;
    validDate(year(), month(), day());
}

    Gregorian& Gregorian::operator=(const Gregorian &src) {
    this->julian_day_number = src.julian_day_number;
    return *this;
}

bool Gregorian::isLeap(int year) const {
    int req0 = year % 4;
    int req1 = year % 100;
    int req2 = year % 400;
    if ((req1 == 0) && !(req2 == 0)) {
        return false;
    }
    if (req0 == 0) {
        return true;
    }
    return false;
}

int Gregorian::year() const {
    int y = convertToJDN(this->julian_day_number, 2);
    return y;
}
unsigned int Gregorian::month() const{
    int m = convertToJDN(this->julian_day_number, 1);
    return m;

}
unsigned int Gregorian::day() const {
    int d = convertToJDN(this->julian_day_number, 0);
    return d;

}

Gregorian Gregorian::operator++(int) {
    Gregorian * g = new Gregorian(*this);
    this->julian_day_number--;
    return *g;
}

Gregorian Gregorian::operator--(int) {
    Gregorian * g = new Gregorian(*this);
    this->julian_day_number--;
    return *g;
}

Gregorian::~Gregorian() {
}

Gregorian& Gregorian::operator++(){
    (this->julian_day_number++);
    return *this;
}
Gregorian& Gregorian::operator--(){
    (this->julian_day_number--);
    return *this;
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
