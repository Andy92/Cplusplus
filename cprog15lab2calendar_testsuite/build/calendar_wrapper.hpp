#ifndef CPROG_CALENDAR_WRAPPER_HPP
#define CPROG_CALENDAR_WRAPPER_HPP

#include "julian.hpp"
#include "gregorian.hpp"
#include "calendar.hpp"

#include <ostream>
#include <string>
#include <utility>

namespace detail {
  struct    julian_tag { };
  struct gregorian_tag { };
}

class CalendarImplBase {
  public:
    virtual bool set_date (int, int, int) = 0;

    virtual bool add_event (std::string const&) = 0;
    virtual bool add_event (std::string const&, int) = 0;
    virtual bool add_event (std::string const&, int, int) = 0;
    virtual bool add_event (std::string const&, int, int, int) = 0;

    virtual bool remove_event (std::string const&) = 0;
    virtual bool remove_event (std::string const&, int) = 0;
    virtual bool remove_event (std::string const&, int, int) = 0;
    virtual bool remove_event (std::string const&, int, int, int) = 0;

    virtual void print (std::ostream&) const = 0;

    virtual void initialize (detail::julian_tag,    void*) const = 0;
    virtual void initialize (detail::gregorian_tag, void*) const = 0;

    virtual ~CalendarImplBase () = default;
};

template<class Cal>
class CalendarImpl : public CalendarImplBase {
  public:
    template<class... Ts>
    CalendarImpl (Ts&&... args)
      : _calendar (std::forward<Ts> (args)...)
    { }

    bool set_date (int year, int month, int day) override {
      return _calendar.set_date (year, month, day);
    }

    bool add_event (std::string const& msg)                               override { return _calendar.add_event (msg); }
    bool add_event (std::string const& msg, int day)                      override { return _calendar.add_event (msg, day); }
    bool add_event (std::string const& msg, int day, int month)           override { return _calendar.add_event (msg, day, month); }
    bool add_event (std::string const& msg, int day, int month, int year) override { return _calendar.add_event (msg, day, month, year); }

    bool remove_event (std::string const& msg)                               override { return _calendar.remove_event (msg); }
    bool remove_event (std::string const& msg, int day)                      override { return _calendar.remove_event (msg, day); }
    bool remove_event (std::string const& msg, int day, int month)           override { return _calendar.remove_event (msg, day, month); }
    bool remove_event (std::string const& msg, int day, int month, int year) override { return _calendar.remove_event (msg, day, month, year); }

    virtual void initialize (detail::julian_tag,    void*) const override;
    virtual void initialize (detail::gregorian_tag, void*) const override;

    void print (std::ostream& stream) const {
      stream << _calendar; 
    }

    Cal _calendar;
};

class CalendarWrapper {
  public:
    template<class Date = lab2::Julian, class... Ts>
    CalendarWrapper (detail::julian_tag, Ts&&... args)
      : _impl (new CalendarImpl<lab2::Calendar<Date>> (std::forward<Ts> (args)...))
    { }

    template<class Date = lab2::Gregorian, class... Ts>
    CalendarWrapper (detail::gregorian_tag, Ts&&... args)
      : _impl (new CalendarImpl<lab2::Calendar<Date>> (std::forward<Ts> (args)...))
    { }

    template<class... Ts>
    bool set_date (Ts&&... args) {
      return _impl->set_date (std::forward<Ts> (args)...);
    }

    template<class... Ts>
    bool add_event (Ts&&... args) {
      return _impl->add_event (std::forward<Ts> (args)...);
    }

    template<class... Ts>
    bool remove_event (Ts&&... args) {
      return _impl->remove_event (std::forward<Ts> (args)...);
    }

    void print (std::ostream& stream) const;

    template<class... Ts>
    void initialize (Ts&&... args) const {
      return _impl->initialize (std::forward<Ts> (args)...);
    }

  private:
    std::unique_ptr<CalendarImplBase> _impl;
};

template<class Cal>
void CalendarImpl<Cal>::initialize (detail::julian_tag, void* dst) const {
  static_cast<natch::environment<CalendarWrapper>::variable_type*> (dst)->construct (detail::julian_tag { }, _calendar);
}

template<class Cal>
void CalendarImpl<Cal>::initialize (detail::gregorian_tag, void* dst) const {
  static_cast<natch::environment<CalendarWrapper>::variable_type*> (dst)->construct (detail::gregorian_tag { }, _calendar);
}

/* ------------------------- */

void CalendarWrapper::print (std::ostream& stream) const {
  return _impl->print (stream);
}

namespace std {
  template<>
  struct hash<CalendarWrapper> {
    std::size_t operator() (CalendarWrapper const&) {
      return 0x00000000;
    }
  };
}

#endif /* include-guard: CPROG_CALENDAR_WRAPPER_HPP */
