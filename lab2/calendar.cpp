#include "calendar.hpp"

using namespace lab2;
template<typename Datetype>
Calendar<Datetype>::Calendar(Calendar const& src) {
	this->calendarDate = src.calendarDate;
}
template<typename Datetype>
Calendar<Datetype>::Calendar() {
	this->calendarDate = Datetype();
}


template<typename Datetype>
bool Calendar<Datetype>::set_date(int y, int m, int d) {
	//Datetype * asd = new Datetype(y, m, d);
	//this->calendarDate = *asd;
	try {
		this->calendarDate = Datetype(y, m, d);
	}
	catch(...) {
		return false;
	}
	return true;
}

template<typename Datetype>
bool Calendar<Datetype>::remove_event(int y, int m, int d) {

	template<typename Datetype>
bool Calendar<Datetype>::add_event(int y, int m, int d) {

int main(){
	Calendar<Gregorian> cal;
	bool asd;
	asd = cal.set_date(2000, 14, 11);
	std::cout << asd << " " << cal.calendarDate << std::endl;
}
