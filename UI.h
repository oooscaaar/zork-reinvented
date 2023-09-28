#pragma once
#include <string>
#include <iostream>
#include "AsciiArt.h"
#include <vector>

using namespace std;

class UI
{
public:
	static void DisplayIntro();
	static void DisplayHelp();
	static void DisplayAbout();
	static void DisplayAscii(vector<string> asciiArt);
};

