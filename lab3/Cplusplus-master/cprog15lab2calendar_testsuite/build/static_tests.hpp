#ifndef CPROG_THE_CALENDAR_STATIC_TESTS
#define CPROG_THE_CALENDAR_STATIC_TESTS

#include "natch.hpp"

#include "date.hpp"
#include "julian.hpp"
#include "gregorian.hpp"

#include "calendar.hpp"

#include <ostream>
#include <type_traits>
#include <string>

NATCH_CREATE_CHECK (can_default_construct, Target {},
  "missing/invalid default-constructor"
);

NATCH_CREATE_CHECK (can_copy_construct, Target (const_val<Target> ()),
  "missing/invalid copy-constructor"
);

NATCH_CREATE_CHECK (can_move_construct, Target (std::move (val<Target> ())),
  "missing/invalid move-constructor"
);

NATCH_CREATE_CHECK (can_construct_from_other, Target (const_val<Target> ()),
  "missing/invalid constructor taking some other instantiation of template<class T> Calendar"
);

NATCH_CREATE_CHECK (can_set_date, bool {val<Target> ().set_date (int {}, int {}, int {})},
  "missing/invalid `cal.set_date (year, month, day)`"
);

NATCH_CREATE_CHECK (can_add_event_0, val<Target> ().add_event ("my birthday - kinda"),
  "missing/invalid `cal.add_event (name)`"
);
NATCH_CREATE_CHECK (can_add_event_1, val<Target> ().add_event ("my birthday - kinda", 12),
  "missing/invalid `cal.add_event (name, day)`"
);

NATCH_CREATE_CHECK (can_add_event_2, val<Target> ().add_event ("my birthday - more accurate", 12, 8),
  "missing/invalid `cal.add_event (name, day, month)`"
);

NATCH_CREATE_CHECK (can_add_event_3, val<Target> ().add_event ("my birthday - fo'real", 12, 8, 1989),
  "missing/invalid `cal.add_event (name, day, month, year)`"
);

NATCH_CREATE_CHECK (can_remove_event_1, val<Target> ().remove_event ("my birthday - kinda", 12),
  "missing/invalid `cal.remove_event (name, day)`"
);

NATCH_CREATE_CHECK (can_remove_event_2, val<Target> ().remove_event ("my birthday - more accurate", 12, 8),
  "missing/invalid `cal.remove_event (name, day, month)`"
);

NATCH_CREATE_CHECK (can_remove_event_3, val<Target> ().remove_event ("my birthday - fo'real", 12, 8, 1989),
  "missing/invalid `cal.remove_event (name, day, month, year)`"
);

template<class U, template<class...> class TT, class... Ts>
TT<U> calendar_tmpl_helper (TT<Ts...>);

NATCH_CREATE_CHECK (can_construct_with_julian,decltype (calendar_tmpl_helper<lab2::Julian> (const_val<Target> ())) (const_val<Target> ()),
  "missing/invalid constructor taking an object of type lab2::Calendar<lab2::Julian>"
);

NATCH_CREATE_CHECK (can_construct_with_gregorian, decltype (calendar_tmpl_helper<lab2::Gregorian> (const_val<Target> ())) (const_val<Target> ()),
  "missing/invalid constructor taking an object of type lab2::Calendar<lab2::Gregorian>"
);

#endif
