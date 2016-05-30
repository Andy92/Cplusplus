FLAGS = -g -Wall -std=c++11
CFLAGS = -c $(FLAGS)

julian.o: julian.cpp julian.hpp
	g++ $(CFLAGS) -o julian.o julian.cpp 

gregorian.o: gregorian.cpp gregorian.hpp
	g++ $(CFLAGS) -o gregorian.o gregorian.cpp

date.o: date.cpp date.hpp
	g++ $(CFLAGS) -o date.o date.cpp

kattistime.o: kattistime.cpp kattistime.h
	g++ $(CFLAGS) -o kattistime.o kattistime.cpp


CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 
FLAGS2 = -std=c++11 -O2 -Wall -pedantic
 
main.out: calendar.hpp julian.o gregorian.o date.o kattistime.o
	 $(CC) $(FLAGS2) -o main.out calendar.cpp calendar.hpp julian.o gregorian.o date.o kattistime.o




