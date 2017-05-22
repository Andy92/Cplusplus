FLAGS = -g -std=c++11
CFLAGS = -c $(FLAGS)

# Characters ===========
Race.o: Characters/Race.cpp Characters/Race.hpp
	g++ $(CFLAGS) -o Characters/Race.o Characters/Race.cpp 

Profession.o: Characters/Profession.cpp Characters/Profession.hpp
	g++ $(CFLAGS) -o Characters/Profession.o Characters/Profession.cpp

Creature.o: Characters/Creature.cpp Characters/Creature.hpp
	g++ $(CFLAGS) -o Characters/Creature.o Characters/Creature.cpp

Character.o: Characters/Character.cpp Characters/Character.hpp
	g++ $(CFLAGS) -o Characters/Character.o Characters/Character.cpp
# ===================

# Environment ==============
Direction.o: Environment/Direction.cpp Environment/Direction.hpp
	g++ $(CFLAGS) -o Environment/Direction.o Environment/Direction.cpp

Room.o: Environment/Room.cpp Environment/Room.hpp
	g++ $(CFLAGS) -o Environment/Room.o Environment/Room.cpp

Environment.o: Environment/Environment.cpp Environment/Environment.hpp
	g++ $(CFLAGS) -o Environment/Environment.o Environment/Environment.cpp
# ===================
Parser.o: Core/Parser.cpp Core/Parser.hpp
	g++ $(CFLAGS) -o Core/Parser.o Core/Parser.cpp

GameLogic.o: Core/GameLogic.cpp Core/GameLogic.hpp
	g++ $(CFLAGS) -o Core/GameLogic.o Core/GameLogic.cpp

# Core ============

Checker.o: Checker.cpp Checker.hpp
	g++ $(CFLAGS) -o Checker.o Checker.cpp

Main.o: Main.cpp Main.hpp
	g++ $(CFLAGS) -o Main.o Main.cpp


# =================

CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 
FLAGS2 = -std=c++11 -O2 -pedantic
 
main: Race.o Profession.o Creature.o Character.o Direction.o Room.o Environment.o Parser.o GameLogic.o Checker.o Main.o
	 $(CC) $(FLAGS2) -o main.out Characters/Race.o Characters/Profession.o Characters/Creature.o Characters/Character.o Environment/Direction.o Environment/Room.o Environment/Environment.o Core/Parser.o Core/GameLogic.o Checker.o Main.o




