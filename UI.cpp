#include "UI.h"


void UI::DisplayIntro() {
	DisplayAscii(AsciiArt::facilitiesEntrance);
	cout << "Welcome to the NASA facilities, eager aerospace engineer.\nYou work here.\nThere is a soldier guarding the entrance.\n\n---------------------------------------------------------" << endl;
	cout << "The soldier asks for your name : ";
}

void UI::DisplayHelp() {
	cout << "//AVAILABLE COMMANDS\nINVENTORY\nLOOK\nINSPECT [OBJECT]\nUSE [OBJECT]\nTAKE [OBJECT]\nDROP [OBJECT]\nGO [DIRECTION]\nI NEED A HERO\nABOUT\nHELP\n---------------------------------------------------------" << endl;
}

void UI::DisplayAbout() {
	DisplayAscii(AsciiArt::about);
}

void UI::DisplayAscii(vector<string> asciiArt) {
	cout << "\n";
	for (string line : asciiArt) {
		cout << line << endl;
	}
	cout << "\n";
}



