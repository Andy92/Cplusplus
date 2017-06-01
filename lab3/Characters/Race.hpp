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
		Human();

	};

	class Orc: public Race
	{
	public:
		Orc();
	};

	class Bandit: public Race
	{
	public:
		Bandit();
	};

	class Dragon: public Race
	{
	public:
		Dragon();
	};

#endif