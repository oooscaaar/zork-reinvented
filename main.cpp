#include <cstdlib>
#include <iostream>
#include "World.h"
#include "Player.h"


using namespace std;

//TODO: Extract all ASCII art and functions to its own class
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

vector<string> TrimUserInput(string input) {
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

int main() {

	World world;
	Player* player = (Player*)world.FindEntityByType(EntityType::PLAYER);

	printEntrance();
	cout << "\nWelcome to the NASA facilities, eager aerospace engineer.\nYou work here.\nThere is a soldier guarding the entrance.\nThe soldier asks for your name: " << endl;
	
	string playerName;

	while (playerName.empty()) {
		cin >> playerName;
	}

	player->setName(playerName);
	cout << "Ok " << player->name << ", to let you pass, first I need to verify your NASA unique ultra secret credential." << endl;

	// Handle user input
	string input;
	while (world.GetGameState() != GameState::GAMEOVER) {
		getline(cin >> ws, input);
		vector<string> commands = TrimUserInput(input);
		world.HandleUserInput(commands);
	}

	return 0;

}

