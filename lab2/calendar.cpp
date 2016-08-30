#include "calendar.hpp"

using namespace lab2;
/*
int main(){
	set_k_time(0);
	Calendar<Julian> a;
	Calendar<Gregorian> b;
	a.add_event("fizbar", 12,8,2015);
	a.set_date(1900,1,1);
	a.add_event("birbaz", 12,10);
	a.add_event("foobar", 12);
	a.add_event("fizbar", -1,-1,-1);
	a.add_event("fizbar", 0,0,0);
	a.remove_event("foobar", 12,8,2015);
	Calendar<Gregorian> c(a);
	std::cout << c;
}

set_k_time 0
default-construct $A julian
default-construct $B gregorian
add_event $A fizbar 12 8 2015
set_date $A 1900 1 1
add_event $A birbaz 12 10
add_event $A foobar 12
add_event $A fizbar -1 -1 -1
add_event $A fizbar 0 0 0 
remove_event $A foobar 12 8 2015
copy-construct $C gregorian $A
print $A
print $B
print $C
*/



int main(){
	set_k_time(0);
	Calendar<Gregorian> a;
	std::cout << a;
	a.set_date(2012,2,29);
	a.add_event("pNGVXBK", 7,2);
	a.remove_event("pNGVXBK", 11,-9);
	a.set_date(1990, 2, 29);
	std::cout << a;
	a.set_date(2010, 2, 29);
	a.set_date(1996, 2, 29);
	a.add_event("HCJygYh", 15, 2, 2013);
	a.remove_event("HCJygYh", 7, 8, 1987);
	a.set_date(1995, 2, 29);
	std::cout << a;
}

/*
1: default-construct $C gregorian
2: print $C
3: set_date $C 2012 2 29
4: add_event $C pNGVXBK 7 2
5: remove_event $C pNGVXBK 11 -9
6: set_date $C 1990 2 29
7: print $C
8: set_date $C 2010 2 29
9: set_date $C 1996 2 29
10: add_event $C HCJygYh 15 2 2013
11: remove_event $C HCJygYh 7 8 1987
12: set_date $C 1995 2 29
13: print $C
*/