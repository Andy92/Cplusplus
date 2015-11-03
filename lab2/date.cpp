#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include "date.hpp"

using namespace lab2;

/*Date::Months = {
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
		}
*/
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
}
int main () {
}
