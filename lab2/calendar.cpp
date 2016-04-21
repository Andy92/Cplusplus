#include "calendar.hpp"

using namespace lab2;

template<typename Datetype>
Calendar<Datetype>::Calendar(Calendar const& src) {
	this->calendarDate = src.calendarDate;
}
template<typename Datetype>
Calendar<Datetype>::Calendar() {
	this->calendarDate = new Datetype();
}


template<typename Datetype>
bool Calendar<Datetype>::set_date(int y, int m, int d) {
	//Datetype * asd = new Datetype(y, m, d);
	//this->calendarDate = *asd;
	try {
		delete this->calendarDate;
		this->calendarDate = new Datetype(y, m, d);
	}
	catch(...) {
		return false;
	}
	return true;
}

template<typename Datetype>
bool Calendar<Datetype>::remove_event(int y, int m, int d) {
	return false;
}



template<typename Datetype>
bool Calendar<Datetype>::add_event(std::string input, int y, int m, int d) {
	Datetype *date = new Datetype(y,m,d);
	int index = -1;
	// check if date is in vector

	for(int i=0;i<eventDate.size();++i) {
		if(*date == eventDate[i]) {
			delete date;
			return false;
		}
		index = i;
	}
	event.push_back(input);
	eventDate.push_back(*date);
	std::cout << event[0] << eventDate[0] << std::endl;

	
	return true;
}

int main(){
	Calendar<Gregorian> cal;
	bool asd;
	asd = cal.set_date(2000, 10, 11);
	asd = cal.add_event("yasdo", 2000, 10, 11);
	asd = cal.add_event("yo", 2000, 10, 11);
	std::cout << asd << " " << *cal.calendarDate << std::endl;
}
