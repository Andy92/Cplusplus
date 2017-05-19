
#include "Parser.hpp"


 	//std::string keywords[]= 

	std::vector<std::string> Parser::cmd = {
		"go",
		"help",
		"time",
		"exit"
	};

	std::vector<std::string> Parser::keyw{
		"west",
		"east",
		"north",
		"south"
	};


void Parser::Parse(std::string input) {


	transform(input.begin(), input.end(), input.begin(),::tolower);

	int commandInt = -1; 
	int keywordInt = -1; 
	for(int i=0; i<cmd.size(); ++i) { //command iteration
		if(input.find(cmd.at(i)) == 0) {
			input = input.substr(cmd.at(i).length());
			commandInt = i;
		}
	}

	switch(commandInt) {
		case 0 : std::cout << "GO command recognized" << std::endl;
			if(input.find(" ")==0) { // Get whitespace
				input = input.substr(1);	// remove whitespace
			} else {
				std::cerr << "ERROR: Whitespace not present.";
				break;
			}
			// Get the keyword after GO
			for(int i=0;i<keyw.size();++i){
				if(input.find(keyw.at(i)) == 0) {
					input = input.substr(keyw.at(i).length());
					keywordInt = i;
				}
			}
			switch(keywordInt) {
				case 0 : std::cout << "WEST keyword registered";
					break;
				case 1 : std::cout << "EAST keyword registered";
					break;
				case 2 : std::cout << "NORTH keyword registered";
					break;
				case 3 : std::cout << "SOUTH keyword registered";
					break;
				default:
					std::cout << "No keyword recognized after GO, try again!";
					break;
			}
			std::cout << std::endl;
			break;
		case 1 : std::cout << "HELP command recognized" << std::endl;
			break;
		case 2 : std::cout << "TIME command recognized" << std::endl;
			break;
		case 3 : std::cout << "EXIT command recognized" << std::endl;
			break;
		default:
			std::cout << "wrong command! or command not recognized, type HELP" << std::endl;
			break;
	}

	
}
