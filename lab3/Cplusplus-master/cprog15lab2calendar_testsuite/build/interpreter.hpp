#ifndef CPROG_THE_CALENDAR_INTERPRETER_HPP
#define CPROG_THE_CALENDAR_INTERPRETER_HPP

#include "date.hpp"
#include "julian.hpp"
#include "gregorian.hpp"
#include "calendar.hpp"

#include "natch.hpp"
#include "calendar_wrapper.hpp"
#include "kattistime.h"
#include "ical_helper.hpp"

#include <memory>
#include <locale>
#include <string>
#include <algorithm>
#include <type_traits>
#include <deque>
#include <vector>

template<class...>
class calendar_interpreter
  : public natch::interpreter<natch::environment<CalendarWrapper>>
{
  private:
    using _base = natch::interpreter<natch::environment<CalendarWrapper>>;

  protected:
    using _base::RI;

  public:
    using environment_type = typename _base::environment_type;
    using Calendar         = typename environment_type::variable_type;

    calendar_interpreter (natch::basic_environment const& be)
      : _base (be)
    {
      RI ("set_k_time", +[] (time_t request) {
        set_k_time (request);
      });

      RI ("default-construct", +[] (Calendar& dst, std::string const& type) {
        /**/ if (type ==    "julian") { dst.construct (detail::julian_tag    { }); }
        else if (type == "gregorian") { dst.construct (detail::gregorian_tag { }); }
        else                          { throw natch::test_error ("unrecognized type in default-construct"); }
      });

      RI ("destruct", +[] (Calendar& dst) {
        dst.destruct ();
      });

      RI ("copy-construct", +[] (Calendar& dst, std::string const& type, Calendar const& rhs) {
        /**/ if (type ==    "julian") { rhs->initialize (detail::   julian_tag { }, static_cast<void*> (&dst)); }
        else if (type == "gregorian") { rhs->initialize (detail::gregorian_tag { }, static_cast<void*> (&dst)); }
        else                          { throw natch::test_error ("unrecognized type in default-construct"); }
      });

      RI ("print", +[] (Calendar const& src, environment_type& env) {

        std::stringstream ical_ss; {
          src->print (ical_ss);
        }

        std::map<std::string, std::vector<std::string>> event_map;

        ical::Entity ical_entity = ical::parse (ical_ss);
        std::deque<ical::Entity const*> entities ({ &ical_entity });


        /* walk through ical-entities to find VEVENTS */

        while (entities.empty () == false) {
          ical::Entity const& e = *entities.front (); entities.pop_front ();

          for (auto const& event : e.children ("VEVENT")) {
            std::string event_date = event.property ("DTSTART");
            std::string event_desc = event.property ("SUMMARY");

            event_date = event_date.substr (0, event_date.find ("T"));

            event_date = event_date.size () != 8 ? event_date : event_date.substr (2, 6);
            event_desc = event_desc.size () != 0 ? event_desc : event.property ("DESCRIPTION");

            if (event_date.empty () || event_desc.empty ()) 
              throw natch::logic_error ("found VEVENT with missing DTSTART or [SUMMARY | DESCRIPTION]: aborting!");

            event_map[event_date].push_back (event_desc);
          }

          for (auto const& event : e.children ())
            entities.push_back (&event);
        }


        /* make event order deterministic */

        for (auto& entry : event_map)
          std::sort (entry.second.begin (), entry.second.end ());


        /* output event data */

        for (auto const& event : event_map) {
          std::string joined;

          for (auto const& desc : event.second) {
            joined += desc + ", ";
          }

          if (joined.size () > 2)
            joined.erase (joined.size () - 2);

          if (event.second.size ())
            env.output ("Date(" + event.first + ")", "Events = [ " + joined + " ]");
        }
      });

      RI ("add_event", +[] (Calendar& lhs, std::string const& event_name, std::vector<int> args, environment_type& env) {
        bool result;

        switch (args.size ()) {
          case 0: result = lhs->add_event (event_name);                            break;
          case 1: result = lhs->add_event (event_name, args[0]);                   break;
          case 2: result = lhs->add_event (event_name, args[0], args[1]);          break;
          case 3: result = lhs->add_event (event_name, args[0], args[1], args[2]); break;
          default:
            throw natch::test_error ("Invalid number of arguments to add_event instruction");
        }

        env.output ("return-value", result);
      });

      RI ("remove_event", +[] (Calendar& lhs, std::string const& event_name, std::vector<int> args, environment_type& env) {
        bool result;

        switch (args.size ()) {
          case 0: result = lhs->remove_event (event_name);                            break;
          case 1: result = lhs->remove_event (event_name, args[0]);                   break;
          case 2: result = lhs->remove_event (event_name, args[0], args[1]);          break;
          case 3: result = lhs->remove_event (event_name, args[0], args[1], args[2]); break;
          default:
            throw natch::test_error ("Invalid number of arguments to add_event instruction");
        }

        env.output ("return-value", result);
      });

      RI ("set_date", +[] (Calendar& lhs, int year, int month, int day, environment_type& env) {
        env.output ("return-value", lhs->set_date (year, month, day));
      });
    }
};

#endif
