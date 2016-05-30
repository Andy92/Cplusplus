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
// Sets the current date of calendar.
template<typename Datetype>
bool Calendar<Datetype>::set_date(int y, int m, int d) {
	try {
		delete this->calendarDate;
		this->calendarDate = new Datetype(y, m, d);
	}
	catch(...) {
		return false;
	}
	return true;
}
 // Main remove method
template<typename Datetype>
bool Calendar<Datetype>::remove_event(std::string input, int d, int m, int y) {
	Datetype *date = new Datetype(y,m,d);
	for(int i=0;i<eventDate.size();++i) {
		if(*date == eventDate[i]) {
			delete date;
			event.erase(event.begin()+i);
			eventDate.erase(eventDate.begin()+i);
			std::cout << event[i] << " " << eventDate[i] << std::endl;
			return true;
		}
	}
	std::cout << "Event does not exist" << std::endl;

	return true;
}

template<typename Datetype>
bool Calendar<Datetype>::remove_event(std::string input, int d, int m) {
	int y = calendarDate->year();
	return this->remove_event(input,d,m,y);
}
	template<typename Datetype>
bool Calendar<Datetype>::remove_event(std::string input, int d) {
	int y = calendarDate->year();
	int m = calendarDate->month();
	return this->remove_event(input,d,m,y);
}
// Main add event method
template<typename Datetype>
bool Calendar<Datetype>::add_event(std::string input, int d, int m, int y) {
	Datetype *date = new Datetype(y,m,d);
	//int index = -1;
	// check if date is in vector

	for(int i=0;i<eventDate.size();++i) {
		if(*date == eventDate[i]) {
			if(input == event[i]) {
				delete date;
				std::cout << "Event already exist" << std::endl;
				return false;
			}
		}
		//index = i;
	}
	event.push_back(input);
	eventDate.push_back(*date);
	
	return true;
}

template<typename Datetype>
bool Calendar<Datetype>::add_event(std::string input, int d, int m) {
	int y = calendarDate->year();
	return this->add_event(input,d,m,y);
}

template<typename Datetype>
bool Calendar<Datetype>::add_event(std::string input, int d) {
	int y = calendarDate->year();
	int m = calendarDate->month();
	return this->add_event(input,d,m,y);
}


int main(){
	Calendar<Gregorian> cal;
	cal.set_date(2000, 12, 2);
	cal.add_event("Basketträning", 4, 12, 2000);
	cal.add_event("Basketträning", 11, 12, 2000);
	cal.add_event("Nyårsfrukost", 1, 1, 2001);
	cal.add_event("Första advent", 1); // år = 2000, månad = 12
	cal.add_event("Vårdagjämning", 20, 3); // år = 2000
	cal.add_event("Julafton", 24, 12);
	cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
	cal.add_event("Julafton", 24); // En likadan händelse samma datum ska
	// ignoreras och inte sättas in i kalendern
	cal.add_event("Min första cykel", 20, 12, 2000);
	cal.remove_event("Basketträning", 4);
	std::cout << cal; // OBS! Vårdagjämning och första advent är
	// före nuvarande datum och skrivs inte ut
	std::cout << "----------------------------------------" << std::endl;
	cal.remove_event("Vårdagjämning", 20, 3, 2000);
	cal.remove_event("Kalle Anka hälsar god jul", 24, 12, 2000);
	cal.set_date(2000, 11, 2);
	if (! cal.remove_event("Julafton", 24)) {
	std::cout << " cal.remove_event(\"Julafton\", 24) tar inte"<< std::endl << " bort något eftersom aktuell månad är november" << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	std::cout << cal;
}