#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef RACE_HPP
#define RACE_HPP
	class Race {
		public:
		std::string id;
		float rhp = 0;
		float rstr = 0;
		Race(std::string identifier);
		std::string toString();
	};

	class Human : public Race
	{
	public:
		Human(std::string identifier);

	};

	class Orc: public Race
	{
	public:
		Orc(std::string identifier);
	};

#endif