
#include "Parser.hpp"

 	//std::string keywords[]= 

	std::vector<std::string> Parser::cmd = {
		"go",
		"help",
		"time",
		"exit",
		"fight"
	};

	std::vector<std::string> Parser::keyw{
		"west",
		"east",
		"north",
		"south"
	};


int Parser::Parse(std::string input) {


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
				std::cerr << "ERROR: Whitespace not present." << std::endl;
				return -1;
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
				case 0 : std::cout << "WEST keyword registered" << std::endl;
					return 0;
					break;
				case 1 : std::cout << "EAST keyword registered" << std::endl;
					return 1;
					break;
				case 2 : std::cout << "NORTH keyword registered" << std::endl;
					return 2;
					break;
				case 3 : std::cout << "SOUTH keyword registered" << std::endl;
					return 3;
					break;
				default:
					std::cout << "No keyword recognized after GO, try again!" << std::endl;
					return -1;
					break;
			}
		case 1 : std::cout << "HELP command recognized" << std::endl;
			return 666;
			break;
		case 2 : std::cout << "TIME command recognized" << std::endl;
			return 22;
			break;
		case 3 : std::cout << "EXIT command recognized" << std::endl;
			return 33;
			break;
		case 4 : std::cout << "FIGHT command recognized" << std::endl;
			return 44;
			break;
		default:
			std::cout << "wrong command! or command not recognized, type HELP" << std::endl;
			return -1;
			break;
	}

	
}
