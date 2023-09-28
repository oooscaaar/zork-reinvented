#include <cstdlib>
#include <iostream>
#include "World.h"
#include "Player.h"
#include "Utils.h"
#include "UI.h"
#include "AsciiArt.h"


using namespace std;

//TODO: [REFACTOR] Extract all ASCII art and functions to its own class

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
	Player* player = (Player*)world.FindEntityByType(EntityType::PLAYER);

	UI::DisplayAscii(AsciiArt::hubbleTelescopeRoom);
	cout << "\nWelcome to the NASA facilities, eager aerospace engineer.\nYou work here.\nThere is a soldier guarding the entrance.\nThe soldier asks for your name: ";
	
	string playerName;

	while (playerName.empty()) {
		getline(cin >> ws, playerName);
	}

	player->SetName(playerName);

	cout << "---------------------------------------------------------" << endl;
	cout << "SOLDIER: Ok " << player->name << ", to let you pass, first I need to verify your NASA unique ultra secret credential." << endl;
	cout << "\n[hint] Type HELP to get a list of available commands.\n";
	cout << "---------------------------------------------------------" << endl;

	// Handle user input
	string input;
	while (world.GetGameState() != GameState::GAMEOVER) {
		cout << "> ";
		getline(cin >> ws, input);
		cout << "---------------------------------------------------------" << endl;
		vector<string> commands = Utils::TrimUserInput(input);
		world.HandleUserInput(commands);
	}

	return 0;

}

