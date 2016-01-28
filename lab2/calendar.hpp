#include "julian.hpp"
#include "gregorian.hpp"

namespace lab2 {
	template<typename Datetype> class Calendar {
	public:
		Datetype calendarDate;
		bool set_date(int y, int m, int d);
		Calendar<Datetype>(Calendar const& src);
		Calendar<Datetype>();
	};
}
