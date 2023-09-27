#include "World.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include "Exit.h"
#include "Utils.h"
#include "UI.h"
#include "AsciiArt.h"

#include <iostream>

using namespace std;

World::World() {



	// Rooms
	Room* facilitiesEntrance = new Room("NASA Facilities entrance", "You are talking to a guard. He asks for an ID card in order to let you pass the security check and access to the NASA building. \n\nType HELP to get a list of available commands.", AsciiArt::facilities);
	Room* hall = new Room("Main Hall", "The guard lets you access the building. You are in the main hall. It's quite a big building. Luckily you took a MAP so you can get to your office.", AsciiArt::facilities);
	Room* hubbleTelescopeRoom = new Room("Hubble Telescope Room", "Finally, you mange to access the room.You see a huge TELESCOPE in the middle of the chamber.You are full of confidence, you can save the world.", AsciiArt::facilities);
	Room* quantumComputerRoom = new Room("Quantum Computer Room", "Let's crack some cyphered secrets", AsciiArt::facilities);
	Room* playersOffice = new Room("Your Office", "This is your humble office. It's equiped with a COMPUTER, a desk and a huge american FLAG on the wall.", AsciiArt::facilities);

	// Exits
	Exit* entranceToHall = new Exit("Building door", "Access to the main hall.", DirectionType::NORTH, facilitiesEntrance, hall);
	Exit* hallToEntrance = new Exit("Door to the exterior", "Exit from the building.", DirectionType::SOUTH, hall, facilitiesEntrance);
	Exit* hallToQuantumComputerRoom = new Exit("Quantum Computer door", "Obviously, this door is closed with a security key", DirectionType::NORTH, hall, quantumComputerRoom);
	Exit* quantumComputerRoomToHall = new Exit("Door to the hall", "Return to the main hall", DirectionType::SOUTH, quantumComputerRoom, hall);
	Exit* hallToPlayersOffice = new Exit("Door to your office", "Go back to work!", DirectionType::EAST, hall, playersOffice);
	Exit* playersOfficeToHall = new Exit("Door to the main hall", "Maybe it's time for a coffee, right?", DirectionType::WEST, playersOffice, hall);
	Exit* hallToHubbleTelescopeRoom = new Exit("Door to the Hubble Telescope", "F*ck, I'm not allowed to gaze at the stars.", DirectionType::WEST, hall, hubbleTelescopeRoom);
	Exit* hubbleTelescopeToHall = new Exit("Door to the Hubble Telescope", "Maybe it's time to get out of this forbidden room.", DirectionType::EAST, hubbleTelescopeRoom, hall);


	// Items
	Item* map = new Item("MAP", "Map of the building");
	Item* idCard = new Item("ID", "Even if you look like a terrorist on that photo, this is your NFC ID card.");

	// Player
	player = new Player("John Doe", "You're a 47 years old Aerospace engineer", facilitiesEntrance);

	entities.push_back(facilitiesEntrance);
	entities.push_back(hall);
	entities.push_back(hubbleTelescopeRoom);
	entities.push_back(quantumComputerRoom);
	entities.push_back(playersOffice);
	entities.push_back(map);
	entities.push_back(player);
	
	// Forced to add these two to the world due to an improper "FindEntities" implementation. I'd have probably done different with more time.
	entities.push_back(map);
	entities.push_back(idCard);

	player->Add(map);
	player->Add(idCard);

	gameState = GameState::RUNNING;

	// Add exits to rooms
	facilitiesEntrance->Add(entranceToHall);
	hall->Add(hallToEntrance);
	hall->Add(hallToHubbleTelescopeRoom);
	hall->Add(hallToPlayersOffice);
	hall->Add(hallToQuantumComputerRoom);
	quantumComputerRoom->Add(quantumComputerRoomToHall);
	playersOffice->Add(playersOfficeToHall);
	hubbleTelescopeRoom->Add(hubbleTelescopeToHall);
}

World::~World() {

}

// TODO: Probably, we won't need a list of entities in the whole world so move to Entity classprobably.
Entity* World::FindEntityByName(string name)
{
	for (Entity* e : entities)
	{
		// TODO: Avoid using this function when special characters. i.e. whitespaces.
		if (Utils::ToLower(e->name) == name) {
			return e;
		}
	}

	return nullptr;
}

// TODO: Probably, we won't need a list of entities in the whole world so move to Entity classprobably.
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
			UI::DisplayHelp();
		}
		else if (commands[0] == "about") {
			UI::DisplayAbout();
		}
		else if (commands[0] == "inventory") {
			player->DisplayInventory();
		}
		// Just for debugging
		else if (commands[0] == "whereami") {
			cout << "You're in " << player->getLocationName() << endl;
		}
		else {
			//TODO: Randomize unsupported command messages.
			cout << "Sorry but I don't understand what you mean.\nType HELP to get a list of available commands." << endl;
		}
		break;
	}
	case 2:
	{
		if (commands[0] == "inspect") { break; }
		if (commands[0] == "use") { break; }
		if (commands[0] == "take") {
			Entity* entityToTake = FindEntityByName(commands[1]);
			if (entityToTake->GetParent() == player->location) {
				player->Add(entityToTake);
			}
			break;
		}
		if (commands[0] == "go") { player->Go(commands[1]); break; }
		if (commands[0] == "drop") {
			Entity* entityToDrop = FindEntityByName(commands[1]);
			if ( entityToDrop != NULL) {
				player->Remove(entityToDrop);
				cout << "You dropped the " << "\"" << entityToDrop->name << "\"" << endl;
			}
			else {
				cout << "You don\'t have an " << "\"" << commands[1] << "\"" << endl;
			}
			break;
		}
		
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
