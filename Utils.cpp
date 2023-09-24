#include "Utils.h"

vector<string> Utils::TrimUserInput(string input) {
	string delimiter = " ";
	size_t pos = 0;
	string token;
	vector<string> trimmedInput;
	while ((pos = input.find(delimiter)) != std::string::npos) {
		token = input.substr(0, pos);
		trimmedInput.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	trimmedInput.push_back(input);
	return trimmedInput;
}
