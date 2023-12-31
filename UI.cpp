#include "UI.h"


void UI::DisplayIntro() {
	DisplayAscii(AsciiArt::facilitiesEntrance);
	cout << "Welcome to the NASA facilities, eager aerospace engineer.\nYou work here.\nThere is a guard controlling the access at the entrance.\n\n---------------------------------------------------------" << endl;
	cout << "You stop the car by the guard house,\nand the guard, dressed with a military uniform\nasks for your name: ";
}

void UI::DisplayHelp() {
	cout << "//AVAILABLE COMMANDS\nINVENTORY\nLOOK AROUND\nINSPECT [OBJECT]\nUSE [OBJECT]\nTAKE [OBJECT]\nDROP [OBJECT]\nGO [DIRECTION]\nWHERE AM I\nABOUT\nHELP\n---------------------------------------------------------" << endl;
}

void UI::DisplayAbout() {
	DisplayAscii(AsciiArt::about);
}

void UI::DisplayEnd() {
	DisplayAscii(AsciiArt::finalScene);
}

void UI::DisplayAscii(vector<string> asciiArt) {
	cout << "\n";
	for (string line : asciiArt) {
		cout << line << endl;
	}
	cout << "\n";
}



