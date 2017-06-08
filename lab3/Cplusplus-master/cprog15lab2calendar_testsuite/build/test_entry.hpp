#ifndef TEST_ENTRY_HPP
#define TEST_ENTRY_HPP

#include "date.hpp"
#include "julian.hpp"
#include "gregorian.hpp"
#include "calendar.hpp"

#include "kattistime.h"

#include "interpreter.hpp"
#include "static_tests.hpp"
#include "natch.hpp"


template<class...>
struct success_helper : std::true_type { };

template<template<class...> class interpreter, class T, template<class> class... traits>
using CalendarChecker = typename natch::conditionally_instantiate<
  success_helper, natch::static_fail_handler, lab2::Calendar<T>,
  traits...,

  can_default_construct,
  can_copy_construct,
  can_move_construct,
  can_construct_from_other,

  can_set_date,

  can_add_event_0,
  can_add_event_1,
  can_add_event_2,
  can_add_event_3,

  can_remove_event_1,
  can_remove_event_2,
  can_remove_event_3,

  can_construct_with_julian,
  can_construct_with_gregorian
>::type;

// in order to make sure that both lab2::Calendar<lab2::Julian> and lab2::Calendar<lab2::Gregorian>
// works we need some indirection, and only run the interpreer if both instantiations pass our
// tests (see CalendarChecker + documentation)

template<class... Ts, class... Us>
void
indirection (success_helper<Ts...>, success_helper<Us...>, natch::basic_environment& env) {
  calendar_interpreter<Ts..., Us...> {env}.run ();
}

template<class T1, class T2>
void
indirection (T1, T2, natch::basic_environment& env) {
  T1 {env}.run ();
}

template<class... Ts, class T2>
void
indirection (success_helper<Ts...>, T2, natch::basic_environment& env) {
  T2 {env}.run ();
}

void
test_entry (natch::basic_environment& env)
{
  set_k_time (0);

  indirection (
    CalendarChecker<success_helper, lab2::Julian>    {},
    CalendarChecker<success_helper, lab2::Gregorian> {},
    env
  );
}

#endif
