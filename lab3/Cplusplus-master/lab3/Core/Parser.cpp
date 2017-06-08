
#include "Parser.hpp"

 	//std::string keywords[]= 

	std::vector<std::string> Parser::cmd = {
		"go",
		"stats",
		"help",
		"exit",
		"fight",
		"quest",
		"items",
		"inv",
		"shop",
		"talk",
		"spec",
		"desc",
		"look"
	};

	std::vector<std::string> Parser::keyw{
		"west",
		"east",
		"north",
		"south",
		"help"
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
		case 0 : std::cerr << "GO command recognized" << std::endl;
			if(input.find(" ")==0) { // Get whitespace
				input = input.substr(1);	// remove whitespace
			} else {
				std::cout << "You must have whitespace after the GO command." << std::endl;
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
				case 0 : std::cerr << "WEST keyword registered" << std::endl;
					return 0;
					break;
				case 1 : std::cerr << "EAST keyword registered" << std::endl;
					return 1;
					break;
				case 2 : std::cerr << "NORTH keyword registered" << std::endl;
					return 2;
					break;
				case 3 : std::cerr << "SOUTH keyword registered" << std::endl;
					return 3;
					break;
				case 4 : std::cerr << "GO DIRECTIONS command recognized" << std::endl;
					return 4;
					break;
				default:
					std::cout << "No keyword recognized after GO, try again!" << std::endl;
					return -1;
					break;
			}
		case 1 : std::cerr << "STATS command recognized" << std::endl;
			return 666;
			break;
		case 2 : std::cerr << "HELP command recognized" << std::endl;
			return 22;
			break;
		case 3 : std::cerr << "EXIT command recognized" << std::endl;
			return 33;
			break;
		case 4 : std::cerr << "FIGHT command recognized" << std::endl;
			return 44;
			break;
		case 5 : std::cerr << "QUEST command recognized" << std::endl;
			return 55;
			break;
		case 6 : std::cerr << "ITEMS command recognized" << std::endl;
			return 66;
			break;
		case 7 : std::cerr << "INVENTORY command recognized" << std::endl;
			return 77;
			break;
		case 8 : std::cerr << "SHOP command recognized" << std::endl;
			return 88;
			break;
		case 9 : std::cerr << "TALK command recognized" << std::endl;
			return 99;
			break;
		case 10 : std::cerr << "SPEC command recognized" << std::endl;
			return 100;
			break;
		case 11 : std::cerr << "DESC command recognized" << std::endl;
			return 101;
			break;
		case 12 : std::cerr << "LOOK command recognized" << std::endl;
			return 102;
			break;
		default:
			std::cout << "Wrong command! Or command not recognized, type HELP" << std::endl;
			return -1;
			break;
	}

	
}
