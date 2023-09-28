#pragma once

#include <vector>
#include <string>

using namespace std;

class Utils
{
public:
	static vector<string> TrimUserInput(string commands);
	static string ToLower(string input);
	static string ToUpper(string input);

};

