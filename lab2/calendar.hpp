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
				out << "BEGIN:VCALENDAR" 							<< std::endl
					<< "VERSION:2.0" 								<< std::endl
					<< "PRODID:-//hacksw/handcal//NONSGML v1.0//EN" << std::endl
					<< "BEGIN:VEVENT"								<< std::endl
					<< "UID:uid1@example.com"						<< std::endl
					<< "DTSTAMP:" << obj.eventDate[i] << "T000000Z" << std::endl
					<< "ORGANIZER;CN=John Doe:MAILTO:john.doe@example.com" << std::endl
					<< "DTSTART:" << obj.eventDate[i] << "T000000Z" << std::endl
					<< "DTEND:" << obj.eventDate[i] << "T235959Z" 	<< std::endl
					<< "SUMMARY:" << obj.event[i] 					<< std::endl
					<< "END:VEVENT"									<< std::endl
					<< "END:VCALENDAR"								<< std::endl;
				//out << obj.event[i] << " " << obj.eventDate[i] 		<< std::endl;
			}
		    return out;
		}
	};
}
#endif
