#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef RACE_HPP
#define RACE_HPP
	class Race {
		public:
<<<<<<< HEAD
		std::string id;
		float rhp = 0;
		float rstr = 0;
		Race(std::string identifier);
		std::string toString();
=======
		float rhp = 0;
		float rstr = 0;
		virtual std::string toString() = 0;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	};

	class Human : public Race
	{
	public:
		Human();
<<<<<<< HEAD
=======
		virtual std::string toString();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965

	};

	class Orc: public Race
	{
	public:
		Orc();
<<<<<<< HEAD
=======
		virtual std::string toString();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	};

	class Bandit: public Race
	{
	public:
		Bandit();
<<<<<<< HEAD
=======
		virtual std::string toString();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	};

		class Knight: public Race
	{
	public:
		Knight();
<<<<<<< HEAD
=======
		virtual std::string toString();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	};

	class Dragon: public Race
	{
	public:
		Dragon();
<<<<<<< HEAD
=======
		virtual std::string toString();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	};

#endif