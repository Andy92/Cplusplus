#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef PARSER_HPP
#define PARSER_HPP

class Parser {
public:
    static std::vector<std::string> cmd;	//declaration
	static std::vector<std::string> keyw;

	
	int Parse(std::string input);
};
#endif
