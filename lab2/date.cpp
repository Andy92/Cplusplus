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

const char *weekday2[] = {
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday"
		};

std::vector<std::string> Date::v3(weekday2, weekday2+7); // definition

int Date::Year () {
	return y;
}
unsigned int Date::Month () {
	return m;
}
unsigned int Date::Day () {
	return d;
}
unsigned int Date::days_per_week () {
	return 7;
}
std::string Date::month_name() {
	//return Date::Months[Month-1];
	std::cout << Months[m-1] << std::endl;
}
Date& Date::operator++() {
	if((d-days_months[m-1]) == 0) {
		d = 1;
		if(m == 12) {
			m = 1;
			y++;
		}
		else {
		m++;
		}
	}
	else {
		d++;
	}
	return *this;
}
Date& Date::operator--() {
	if(d == 1) {
		//d = days_months[m-1];
		if(m == 1) {
			m = 12;
			d = days_months[m-1];
			y--;
		} else {
			m--;
			d = days_months[m-1];
		}
	} else {
		d--;
	}
	return *this;
}
Date& Date::operator+=(int n) {
	while(n>days_months[m-1]) {
		if(m==12){
			n -= days_months[m-1];
			m = 1;
			y++;
		} else {
			n -= days_months[m-1];
			m++;
		}
	}
	if(d+n > days_months[m-1]) {
		if(m==12) {
			d = d+n - days_months[m-1];
			m = 1;
			y++;
		} else {
			d = d+n - days_months[m-1];
			m++;
		}
	} else {
		d += n;
	}
	return *this;
}
Date& Date::operator-=(int n) {
	while ((m==1 && n>days_months[11]) || (n>days_months[m-2])){
		if(m==1){
			n -= days_months[11];		//hårdkod
			m = 12;
			y--;
		} else {
			n -= days_months[m-2];
			m--;
		}
	}
	if((m==1) && (d+n > days_months[11])) {
		d = d+n - days_months[11];
		m=12;
		y--;
	} else if(d+n > days_months[m-2]) {
		d = d+n - days_months[m-2];
		m--;
	} else {
		d -= n;
	}
	return *this;
}
std::ostream& operator<<(std::ostream &out, const Date &obj) {
	out << obj.y <<  "-" << obj.m <<  "-" <<obj.d;
	return out;
}

int main () {
}