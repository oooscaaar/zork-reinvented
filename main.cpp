#include <cstdlib>
#include <iostream>
#include "World.h"
#include "Player.h"


using namespace std;

void printEntrance() {
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

int main() {

	World world;

	printEntrance();
	cout << "\nWelcome to the NASA facilities, eager aerospace engineer.\nYou work here.\nThere is a soldier guarding the entrance.\nThe soldier asks for your name: " << endl;
	string playerName;

	while (playerName.empty()) {
		cin >> playerName;
	}

	cout << "Ok " << playerName << ", to let you pass, I need to verify your NASA unique ultra secret credential." << endl;



}

