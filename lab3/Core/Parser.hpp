#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Parser {
public:
    static std::vector<std::string> cmd;	//declaration
	static std::vector<std::string> keyw;

	
	void Parse(std::string input);
};