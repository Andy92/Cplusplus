#include "julian.hpp"
#include "gregorian.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CALENDAR_HPP
#define CALENDAR_HPP


namespace lab2 {
	template<typename Datetype> class Calendar {
	private:
		bool test();
	public:
		Datetype calendarDate;
		std::vector<std::string> event; // definition
		std::vector<Datetype> eventDate; // definition
		bool set_date(int y, int m, int d);
		bool add_event(std::string input, int d, int m, int y);
		bool add_event(std::string input, int d, int m);
		bool add_event(std::string input, int d);
		bool add_event(std::string input);
		bool remove_event(std::string input, int d, int m, int y);
		bool remove_event(std::string input, int d, int m);
		bool remove_event(std::string input, int d);
		bool remove_event(std::string input);
		void print_event();
		template<typename Datetype2> Calendar(Calendar<Datetype2> const& src) {
			calendarDate = src.calendarDate;
			
			int size = src.eventDate.size();
			eventDate.resize(size);
			event.resize(size);
			for(int i=0;i<size;++i) {
				eventDate[i] = src.eventDate[i];
				event[i] = src.event[i];
			}	
		}
			//const Calendar<Datetype>& operator=(const Calendar<Datetype>& src);
		Calendar<Datetype>();


		// operator for calendar
		friend std::ostream& operator<<(std::ostream& out, Calendar const& obj) {

			out << "BEGIN:VCALENDAR" << std::endl;
			int size = obj.eventDate.size();
			for(int i=0;i<size;++i) {
				if(obj.calendarDate <= obj.eventDate[i]) {
					out
						<< "BEGIN:VEVENT"								<< std::endl
						<< "DTSTAMP:" << obj.eventDate[i] << "T000000Z"	<< std::endl
						<< "DTSTART:" << obj.eventDate[i] << "T000000Z"	<< std::endl
						<< "DTEND:" << obj.eventDate[i] <<	"T235959Z"	<< std::endl
						<< "SUMMARY:" << obj.event[i]					<< std::endl
						<< "END:VEVENT"									<< std::endl;
						
					//out << obj.event[i] << " " << obj.eventDate[i] 		<< std::endl;
				}
			}
			out << "END:VCALENDAR"								<< std::endl;
		    return out;
		}
	};
/*
template<typename Datetype>
template<typename Datetype2>
Calendar<Datetype>::Calendar(Calendar<Datetype2> const& src) {
	calendarDate = src.calendarDate;
}
*/
/*
template<typename Datetype>
Calendar<Datetype>::Calendar(Calendar&& src) {
	calendarDate = src.calendarDate;
	src.calendarDate = 0;
}
*/
	template<typename Datetype>
	Calendar<Datetype>::Calendar() {
		calendarDate = Datetype();
	}
	// Sets the current date of calendar.
	template<typename Datetype>
	bool Calendar<Datetype>::set_date(int y, int m, int d) {
		try {
			calendarDate = Datetype(y, m, d);
		}
		catch(std::invalid_argument e) {
			return false;
		}
		return true;
	}
	 // Main remove method
	template<typename Datetype>
	bool Calendar<Datetype>::remove_event(std::string input, int d, int m, int y) {
		try{
			Datetype date = Datetype(y,m,d);

			int size = eventDate.size();
			for(int i=0;i<size;++i) {
				if(date == eventDate[i] && input == event[i]) {
					//std::cout << event[i] << " " << eventDate[i] << std::endl;
					event.erase(event.begin()+i);
					eventDate.erase(eventDate.begin()+i);
					
					return true;
				}
			}

		}
		catch(std::invalid_argument e){
			return false;
		}
		//std::cout << "Event does not exist" << std::endl;

		return false;

	}

	template<typename Datetype>
	bool Calendar<Datetype>::remove_event(std::string input, int d, int m) {
		int y = calendarDate.year();
		return remove_event(input,d,m,y);
	}
		template<typename Datetype>
	bool Calendar<Datetype>::remove_event(std::string input, int d) {
		int y = calendarDate.year();
		int m = calendarDate.month();
		return remove_event(input,d,m,y);
	}
		template<typename Datetype>
	bool Calendar<Datetype>::remove_event(std::string input) {
		int y = calendarDate.year();
		int m = calendarDate.month();
		int d = calendarDate.day();
		return remove_event(input,d,m,y);
	}

	// Main add event method
	template<typename Datetype>
	bool Calendar<Datetype>::add_event(std::string input, int d, int m, int y) {
		try{
			
			Datetype date = Datetype(y,m,d);
		
		
		//int index = -1;
		// check if date is in vector
			int size = eventDate.size();
		for(int i=0;i<size;++i) {
			if(date == eventDate[i]) {
				if(input == event[i]) {
					//std::cout << "Event already exist" << std::endl;
					return false;
				}
			}
			//index = i;
		}
		event.push_back(input);
		eventDate.push_back(date);
		}
		catch(std::invalid_argument e){
			return false;
		}
		return true;
	}

	template<typename Datetype>
	bool Calendar<Datetype>::add_event(std::string input, int d, int m) {
		int y = calendarDate.year();
		return add_event(input,d,m,y);
	}

	template<typename Datetype>
	bool Calendar<Datetype>::add_event(std::string input, int d) {
		int y = calendarDate.year();
		int m = calendarDate.month();
		return add_event(input,d,m,y);
	}

	template<typename Datetype>
	bool Calendar<Datetype>::add_event(std::string input) {
		int y = calendarDate.year();
		int m = calendarDate.month();
		int d = calendarDate.day();
		return add_event(input,d,m,y);
	}
}



#endif

