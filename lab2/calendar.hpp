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
		Datetype * calendarDate;
		bool set_date(int y, int m, int d);
		bool add_event(std::string input, int d, int m, int y);
		bool add_event(std::string input, int d, int m);
		bool add_event(std::string input, int d);
		bool remove_event(std::string input, int d, int m, int y);
		bool remove_event(std::string input, int d, int m);
		bool remove_event(std::string input, int d);
		void print_event();
		Calendar<Datetype>(Calendar const& src);
		Calendar<Datetype>();
		std::vector<std::string> event; // definition
		std::vector<Datetype> eventDate; // definition


		// operator for calendar
		friend std::ostream& operator<<(std::ostream& out, Calendar const& obj) {
			for(int i=0;i<obj.eventDate.size();++i) {
				out << obj.event[i] << " " << obj.eventDate[i] << std::endl;
			}
		    return out;
		}
	};
}
#endif
