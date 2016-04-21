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
		bool add_event(std::string input, int y, int m, int d);
		bool remove_event(int y, int m, int d);
		Calendar<Datetype>(Calendar const& src);
		Calendar<Datetype>();
		std::vector<std::string> event; // definition
		std::vector<Datetype> eventDate; // definition
		
	};
}
#endif
