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
            int a = (14-M)/12;
            int m = M + 12*a -3;
            int y = Y + 4800 - a;
            int d = D;
            this->julian_day_number = d + (153*m + 2)/5 + 365*y + y/4 - 32083;
            //std::cout << this->julian_day_number;
        }
        Julian::Julian() {
                time_t now = time(0);
                std::cout << now << std::endl;
                this->julian_day_number = 2440588 + (now / 86400);
        }
        Julian::Julian(Date const& src) {
            this->julian_day_number = src.julian_day_number;
        }
        std::string Julian::week_day_name() const{
			return v4[(this->julian_day_number % 7) - 1];
		}
		unsigned int Julian::week_day() {
			return (this->julian_day_number % 7) + 1;
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
        bool Julian::isLeap(int y) {
        	if(y % 4 == 0)
        		return true;
        	return false;
        }
        Julian& Julian::operator++(){
            (this->julian_day_number++);
            return *this;
        }
        Julian& Julian::operator--(){
            (this->julian_day_number--);
            return *this;
        }
        Julian Julian::operator++(int) {
        Julian tmp(*this); // copy
        this->julian_day_number++; // pre-increment
        return tmp;   // return old value
    }
     Julian Julian::operator--(int) {
        Julian tmp(*this); // copy
        this->julian_day_number--; // pre-increment
        return tmp;   // return old value
    }
    Date& Julian::operator=(const Date &src) {
    this->julian_day_number = src.julian_day_number;
    return *this;
}


// Convert to gregorian from JDN
    int Julian::convertToJDN(int J, int check) const {
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
    int f = J + j;
    // beräkna resten
    double e = r * f + v;
    double g = mod(e,p) / r;
    double h = u * g + w;
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
double Julian::mod(int a, int b) const {
    double r = a % b;
    return r;
}

// Integer division
double Julian::div(double a, double b) const {
    double r = a / b;
    return r;
}

std::ostream &operator<<(std::ostream& out, const Julian& obj) {
    out << obj.year() <<  "-" << obj.month() <<  "-" << obj.day();
    return out;
}