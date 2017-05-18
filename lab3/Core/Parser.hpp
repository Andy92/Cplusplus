class Parser {
public:
	std::vector<std::string> cmd;
	std::string command = "";
	std::string keyword;
	void Parse(std::string input);
};