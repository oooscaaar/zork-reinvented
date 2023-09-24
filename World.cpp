#include "World.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include <iostream>

using namespace std;

World::World() {

	// Rooms
	Room* facilities_entrance = new Room("NASA Facilities", "You are talking to a guard. He asks for an ID card in order to let you pass the security check and access to the NASA building. \n\nType HELP to get a list of available commands.");
	Room* hall = new Room("Main Hall", "The guard lets you access the building. You are in the main hall. It's quite a big building. Luckily you took a MAP so you can get to your office.");
	Room* hubble_telescope_room = new Room("Hubble Telescope Room", "Finally, you mange to access the room.You see a huge TELESCOPE in the middle of the chamber.You are full of confidence, you can save the world.");
	Room* quantum_computer_room = new Room("Quantum Computer Room", "Let's crack some cyphered secrets");
	Room* players_office = new Room("Your Office", "This is your humble office. It's equiped with a COMPUTER, a desk and a huge american FLAG on the wall.");

	// Items
	Item* map = new Item("Map", "Map of the building", hall);

	// Player
	player = new Player("John Doe", "You're a 47 years old Aerospace engineer", facilities_entrance);

	entities.push_back(facilities_entrance);
	entities.push_back(hall);
	entities.push_back(hubble_telescope_room);
	entities.push_back(quantum_computer_room);
	entities.push_back(players_office);
	entities.push_back(map);
	entities.push_back(player);

	gameState = GameState::RUNNING;

}

World::~World() {

}


Entity* World::FindEntityByName(string name)
{
	for (Entity* e : entities)
	{

		if (e->name == name) {
			return e;
		}
	}

	return nullptr;
}

Entity* World::FindEntityByType(EntityType type)
{
	for (Entity* e : entities)
	{

		if (e->type == type) {
			return e;
		}
	}

	return nullptr;
}

GameState World::GetGameState() {
	return gameState;
}

void World::HandleUserInput(vector<string> commands) {

	switch (commands.size()) {
	case 1:
	{
		if (commands[0] == "help") {
			DisplayHelp();
		}
		else if (commands[0] == "about") {
			DisplayAbout();
		}
		else if (commands[0] == "inventory") {
			player->DisplayInventory();
		}
		else {
			//TODO: Randomize unsupported command messages.
			cout << "Sorry but I don't understand what you mean.\nType HELP to get a list of available commands." << endl;
		}
		break;
	}
	case 2:
	{
		//TODO: Randomize unsupported command messages.
		cout << "Sorry but I don't understand what you mean." << endl;
		break;
	}

	case 4:
	{
		if (commands[0] == "i" && commands[1] == "need" && commands[2] == "a" && commands[3] == "hero") {
			cout << "This command should display a hint." << endl;
		}
		break;
	}

	default: {
		//TODO: Randomize unsupported command messages.
		cout << "Sorry but I don't understand what you mean." << endl;
	}
	}

}


void World::DisplayHelp() {
	cout << "\n--- AVAILABLE COMMANDS ---\nINVENTORY\nLOOK\nLOOK [OBJECT]\nUSE [OBJECT]\nTAKE [OBJECT]\nTAKE [OBJECT]\nDROP [OBJECT]\nGO [DIRECTION]\nI NEED A HERO\nABOUT\nHELP\n-------------------------" << endl;
}

void World::DisplayAbout() {
	cout << "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	cout << "*                                                       *\n";
	cout << "* @author: Oscar Mellado                                *\n";
	cout << "* @date: September 2023                                 *\n";
	cout << "* @context: Advanced programming for AAA videogames     *\n";
	cout << "* @see: https://github.com/oooscaaar                    *\n";
	cout << "*                                                       *\n";
	cout << "*                    /\"\"\\      ,                        *\n";
	cout << "*                   <>^  L____/|                        *\n";
	cout << "*                    \\`) /\\`   , /                        *\n";
	cout << "*                     \\ \\`---' /                         *\n";
	cout << "*                      \\`'\";\\)\\`                          *\n";
	cout << "*                        _/_Y                           *  \n";
	cout << "*                                               1557798 *\n";
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n";
}

