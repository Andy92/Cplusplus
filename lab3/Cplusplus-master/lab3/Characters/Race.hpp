#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef RACE_HPP
#define RACE_HPP
	class Race {
		public:
		float rhp = 0;
		float rstr = 0;
		virtual std::string toString() = 0;
	};

	class Human : public Race
	{
	public:
		Human();
		virtual std::string toString();

	};

	class Orc: public Race
	{
	public:
		Orc();
		virtual std::string toString();
	};

	class Bandit: public Race
	{
	public:
		Bandit();
		virtual std::string toString();
	};

		class Knight: public Race
	{
	public:
		Knight();
		virtual std::string toString();
	};

	class Dragon: public Race
	{
	public:
		Dragon();
		virtual std::string toString();
	};

#endif