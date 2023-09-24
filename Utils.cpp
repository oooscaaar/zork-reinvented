#include "Utils.h"
#include <algorithm>
#include <iostream>

vector<string> Utils::TrimUserInput(string input) {
	string delimiter = " ";
	size_t pos = 0;
	string token;
	vector<string> trimmedInputs;

	// Trim whitespaces
	while ((pos = input.find(delimiter)) != std::string::npos) {
		token = input.substr(0, pos);
		trimmedInputs.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	trimmedInputs.push_back(input);

	// We decided to lower case all commands to reduce if-cases string compares in the command handler.
	vector<string> loweredInputs;
	for (string input : trimmedInputs) {
		std::transform(input.begin(), input.end(), input.begin(), [&](unsigned char input) {
			return std::tolower(input);
		});
		loweredInputs.push_back(input);
	}

	return loweredInputs;
}
