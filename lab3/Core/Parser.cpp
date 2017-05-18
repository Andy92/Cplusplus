#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Parser.hpp"

std::string commands[]= {"go", "help"};
 std::string keywords[]= {" west", " east", " north", " south"}; //mellanslag patternmatch


 void Parser::Parse(std::string input) {
	for(int i=0; i<2; ++i) { //command iteration
		if(input.find(commands[i]) == 0) {
			command = commands[i];
			input = input.substr(0, commands[i].length());
		}
	}
	if(command.empty())
		std::cout << "wrong command ";
	for(int i = 0; i<4; ++i) {
		if(input.find(keywords[i]) == 0) {
			keyword = keywords[i];
		}
	}
	if(keyword.empty())
		std::cout << "wrong keyword";
}