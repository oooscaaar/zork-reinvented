#include <cstdlib>
#include <iostream>
#include "World.h"
#include "Player.h"
#include "Utils.h"
#include "UI.h"
#include "AsciiArt.h"


using namespace std;


int main() {

	World world;
	Player* player = (Player*)world.FindEntityByType(EntityType::PLAYER);

	UI::DisplayIntro();

	string playerName;
	while (playerName.empty()) {
		getline(cin >> ws, playerName);
	}
	player->SetName(playerName);

	cout << "---------------------------------------------------------" << endl;
	cout << "SOLDIER: Hello " << player->name << ", to let you pass, first I need to\nverify your NASA unique ultra secret ID." << endl;
	cout << "\n[hint] Type HELP to get a list of available commands.\n";
	cout << "---------------------------------------------------------" << endl;

	// Handle user input
	string input;
	while (!world.IsGameOver()) {
		cout << "> ";
		getline(cin >> ws, input);
		cout << "---------------------------------------------------------" << endl;
		vector<string> commands = Utils::TrimUserInput(input);
		world.HandleUserInput(commands);
	}

	system("pause");
	return 0;

}

