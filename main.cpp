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

	UI::DisplayAscii(AsciiArt::facilitiesEntrance);
	cout << "Welcome to the NASA facilities, eager aerospace engineer.\nYou work here.\nThere is a soldier guarding the entrance.\n\n---------------------------------------------------------" << endl;
	
	cout << "The soldier asks for your name : ";
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

