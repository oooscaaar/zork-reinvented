#include "UI.h"


void UI::DisplayIntro() {
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*                                                       *" << endl;
	cout << "*                     ) ) )                        ___  *" << endl;
	cout << "*                    ( ( (                   |     | |  *" << endl;
	cout << "*                     ) ) )                 / \\    |U|  *" << endl;
	cout << "*                  (~~~~~~~~~~)            |---|===|P|  *" << endl;
	cout << "*                   |  NASA  |             |---|   |C|  *" << endl;
	cout << "*                   |        |            /     \\  | |  *" << endl;
	cout << "*                   |     ___|           |   U   | |S|  *" << endl;
	cout << "*                   |   /     \\          |   S   |=|P|  *" << endl;
	cout << "*      __           |  |      .|         |   A   | |A|  *" << endl;
	cout << "*   __|_@|___       |  |  |~~~~~~~~~~~|  |_______| |C|  *" << endl;
	cout << "* =|_ ____ __|=   .'   |  ||~~~~~~~~| |   |@| |@|  |E|  *" << endl;
	cout << "* ___0____0_____/'_____|__||__###___|_|___|_|_|_|__|_|_ *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
}

void UI::DisplayHelp() {
	cout << "//AVAILABLE COMMANDS\nINVENTORY\nLOOK\nINSPECT [OBJECT]\nUSE [OBJECT]\nTAKE [OBJECT]\nDROP [OBJECT]\nGO [DIRECTION]\nI NEED A HERO\nABOUT\nHELP\n---------------------------------------------------------" << endl;
}

void UI::DisplayAbout() {
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	cout << "* @author: Oscar Mellado                                *\n";
	cout << "* @date: September 2023                                 *\n";
	cout << "* @context: Advanced programming for AAA videogames     *\n";
	cout << "* @see: https://github.com/oooscaaar                    *\n";
	cout << "*                                                       *\n";
	cout << "*                                                       *\n";
	cout << "*                    /\"\"\\      ,                        *\n";
	cout << "*                   <>^  L____/|                        *\n";
	cout << "*                    `) /`   , /                        *\n";
	cout << "*                     \\ `---' /                         *\n";
	cout << "*                      `'\";\\) `                         *\n";
	cout << "*                        _/_Y                           *  \n";
	cout << "*                                               1557798 *\n";
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	cout << "---------------------------------------------------------" << endl;
}

void UI::DisplayAscii(vector<string> asciiArt) {
	for (string line : asciiArt) {
		cout << line << endl;
	}
}



