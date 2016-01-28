#include "julian.hpp"


using namespace lab2;
    const char *weekday[] = {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
        };
        std::vector<std::string> v4(weekday, weekday+7); // definition
        Julian::Julian(int Y, int M, int D) {
            validDate(Y, M, D);
            int a = (14-M)/12;
            //std::cout << "a: " << a << std::endl;
            int m = M + 12*a -3;
            int y = Y + 4800 - a;
            //std::cout << "y: " << y << std::endl;
            //std::cout << "m: " << m << std::endl;
            int d = D;
            this->julian_day_number = d + (153*m + 2)/5 + 365*y + y/4 - 32083;
            
            //std::cout << "julus: " << this->julian_day_number << std::endl;
            
        }
        Julian::Julian() {
                //std::cout << now << std::endl;
            //time_t now;
           time_t now = time(0);
            //k_time(&now);
            this->julian_day_number = 2440588 + (now / 86400);
            validDate(year(), month(), day());
        }
        Julian::~Julian() {
        }
        Julian::Julian(Date const& src) {
            this->julian_day_number = src.julian_day_number;
            validDate(year(), month(), day());
        }
        std::string Julian::week_day_name() const{
            int i = this->julian_day_number;
            return v4[(i % 7)];           // no (+1) for the list starts with index 0
        }
        unsigned int Julian::week_day() const {
            int i = this->julian_day_number;
            return (i % 7) + 1;             // +1 for correcting the result
        }
        unsigned int Julian::day() const {
            int d = convertToJDN(this->julian_day_number, 0);
            return d;
        }
        int Julian::year() const {
            int y = convertToJDN(this->julian_day_number, 2);
            return y;
        }
        unsigned int Julian::month() const {
            int m = convertToJDN(this->julian_day_number, 1);
            return m;
        }
        bool Julian::isLeap(int y) const {
            if(y % 4 == 0)
                return true;
            return false;
        }
    Julian& Julian::operator=(const Julian &src) {
    this->julian_day_number = src.julian_day_number;
    return *this;
}

void Julian::validDate(int Y, int M, int D) const {
    if(!isLeap(Y) && M == 2 && D == 29)
        throw std::invalid_argument("invalid date");
    if(Y > 2558 || Y < 1858)
        throw std::invalid_argument("invalid date");
    if((M <= 0 || M > 12) || (D <= 0 ||D > 31))
        throw std::invalid_argument("invalid date");
}

Julian Julian::operator++(int) {
    Julian * g = new Julian(*this);
    this->julian_day_number++;
    return *g;
}

Julian Julian::operator--(int) {
    Julian * g = new Julian(*this);
    this->julian_day_number++;
    return *g;
}

Julian& Julian::operator++(){
    (this->julian_day_number++);
    return *this;
}
Julian& Julian::operator--(){
    (this->julian_day_number--);
    return *this;
}

// 1858 - 2558
// Convert to gregorian from JDN
    int Julian::convertToJDN(int J, int check) const {
    // Parameters for Greg:
    int y1 = 4716;
    int j = 1401;
    int m1 = 2;
    int n = 12;
    int r = 4;
    int p = 1461;
    //
    int v = 3;
    int u = 5;
    int s = 153;
    int w = 2;
    int B = 274277;
    int C = -38;
    // End of parameters
    double f = J + j;
    // berÃ¤kna resten
    double e = r * f + v;
    double g = div(mod(e,p),r);
    double h = u * g + w;
    int D = div(mod(h,s),u) + 1;
    int M = mod(((div(h,s)) + m1),n) + 1;
    int Y = div(e,p) - y1 + div((n + m1 - M),n);
    if(check == 0)
        return D;
    if(check == 1)
        return M;
    if(check == 2)
        return Y;
    return 0;
}           

// modulus
int Julian::mod(int a, int b) const {
    int r = a % b;
    return r;
}

// Integer division
int Julian::div(int a, int b) const {
    int r = a / b;
    return r;
}
