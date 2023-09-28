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
	Room* facilitiesEntrance = new Room("NASA Facilities Entrance", "You are talking to a guard. He asks for an ID card in order to let you pass the security check and access to the NASA building. \n\nType HELP to get a list of available commands.", AsciiArt::facilitiesEntrance);
	Room* hall = new Room("Main Hall", "The guard lets you access the building, and you're now in the main hall. It's quite a big building.", AsciiArt::hall);
	Room* hubbleTelescopeRoom = new Room("Hubble Telescope Room", "You mange to access the room. You see a huge TELESCOPE in the middle of the chamber.You are full of confidence, you can save the world.", AsciiArt::hubbleTelescopeRoom);
	Room* emergencySpaceshipRoom = new Room("Emergency Spaceship Room", "This room hosts an emergency an emergency Spaceship within a TakeOff plaform!", AsciiArt::spaceShip);
	Room* playersOffice = new Room("Your Office", "This is your humble office. It's equiped with a COMPUTER, a desk and a huge american FLAG on the wall.", AsciiArt::playersOffice);

	// Exits
	Exit* entranceToHall = new Exit("Entrance to the Space Center (North)", "Access to the main hall.", DirectionType::NORTH, facilitiesEntrance, hall, "The guard lets you access the building, and you're now in\nthe main hall. It's quite a big building.", true);
	Exit* hallToEntrance = new Exit("South Door", "Exit from the building.", DirectionType::SOUTH, hall, facilitiesEntrance, "You left the building, maybe you should go back and... WORK!");
	Exit* hallToEmergencySpaceshipRoom = new Exit("North Door", "Obviously, this door is closed with a security key", DirectionType::NORTH, hall, emergencySpaceshipRoom, "You enter the room and contemplate a huge spaceship ready to take off. Hurry up, there's no much time left!", true);
	Exit* emergencySpaceshipRoomToHall = new Exit("South Door", "Return to the main hall", DirectionType::SOUTH, emergencySpaceshipRoom, hall, "");
	Exit* hallToPlayersOffice = new Exit("East Door", "Go back to work!", DirectionType::EAST, hall, playersOffice, "This is your humble office.");
	Exit* playersOfficeToHall = new Exit("West Door", "Maybe it's time for a coffee, right?", DirectionType::WEST, playersOffice, hall, "");
	Exit* hallToHubbleTelescopeRoom = new Exit("West Door", "F*ck, I'm not allowed to gaze at the stars.", DirectionType::WEST, hall, hubbleTelescopeRoom, "You've manged to access the telescope room. You see a huge TELESCOPE in the middle of the chamber. You are full of confidence, you can save the world!", true);
	Exit* hubbleTelescopeToHall = new Exit("Door to the Main Hall", "Maybe it's time to get out of this forbidden room.", DirectionType::EAST, hubbleTelescopeRoom, hall, "");


	// Items
	Item* map = new Item("map", "Map of the building", AsciiArt::map);
	Item* idCard = new Item("id", "Even if you look like an alien on that photo, this is your NFC ID card.", AsciiArt::id);
	Item* telescope = new Item("telescope", "The Hubble telescope is amazing. Now you know why it was several decades in the making.", AsciiArt::telescope);
	Item* laptop = new Item("laptop", "That is your computer. Maybe you should start the work day checking your email inbox...", AsciiArt::laptop);
	Item* flag = new Item("flag", "That's your huge and beloved American Flag on the wall.", AsciiArt::flag);
	Item* locker = new Item("locker", "This locker is marked for emergencies. Maybe you should take a look inside.", AsciiArt::locker, ItemType::HOLDER);
	Item* key = new Item("key", "This key opens the emergency spaceship takeoff platform", AsciiArt::key, ItemType::KEY);
	Item* spaceShip = new Item("spaceship", "This ship will take you really far from here. It looks blazingly FAST!", AsciiArt::spaceShip);

	// Player
	player = new Player("John Doe", "You're a 47 years old Aerospace engineer", facilitiesEntrance);

	entities.push_back(facilitiesEntrance);
	entities.push_back(hall);
	entities.push_back(hubbleTelescopeRoom);
	entities.push_back(emergencySpaceshipRoom);
	entities.push_back(playersOffice);
	entities.push_back(map);
	entities.push_back(player);

	// Forced to add these two to the world due to an improper "FindEntities" implementation. I'd have probably done different with more time.
	entities.push_back(map);
	entities.push_back(idCard);

	// Add items to the player
	player->Add(idCard);

	gameState = GameState::RUNNING;

	// Add exits to the rooms
	facilitiesEntrance->Add(entranceToHall);
	hall->Add(hallToEntrance);
	hall->Add(hallToHubbleTelescopeRoom);
	hall->Add(hallToPlayersOffice);
	hall->Add(hallToEmergencySpaceshipRoom);
	emergencySpaceshipRoom->Add(emergencySpaceshipRoomToHall);
	playersOffice->Add(playersOfficeToHall);
	hubbleTelescopeRoom->Add(hubbleTelescopeToHall);

	// Add items to the rooms
	hall->Add(map);
	hubbleTelescopeRoom->Add(telescope);
	hubbleTelescopeRoom->Add(locker);
	locker->Add(key);
	playersOffice->Add(flag);
	playersOffice->Add(laptop);
	emergencySpaceshipRoom->Add(spaceShip);
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

// This handler should had been implemented using the command pattern. I wanted to refactor but I ran out of time :(
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
		else {
			cout << "Sorry but I don't understand what you mean.\nType HELP to get a list of available commands.\n";
			cout << "---------------------------------------------------------" << endl;
		}
		break;
	}
	case 2:
	{
		if (commands[0] == "inspect") { player->Inspect(commands[1]);break; }
		else if(commands[0] == "look" && commands[1] == "around") {
			player->Look();
			break;
		}
		else if (commands[0] == "use") { player->Use(commands[1]); break; }
		else if (commands[0] == "take") {
			player->Take(commands[1]);
			break;
		}
		else if (commands[0] == "go") { player->Go(commands[1]); break; }
		else if (commands[0] == "drop") {
			player->Drop(commands[1]); break;
		}
		else if (commands[0] == "look") {
			cout << "Use INSPECT to gather more information about items in your inventory" << endl;
			break;
		}

		cout << "Sorry but I don't understand what you mean.\n";
		cout << "---------------------------------------------------------" << endl;
		break;
	}

	case 3:
	{
		if (commands[0] == "where" && commands[1] == "am" && commands[2] == "i") {
			cout << "You're in " << player->getLocationName() << "\n---------------------------------------------------------" << endl;
			break;
		}
	}

	default: {
		cout << "Sorry but I don't understand what you mean.\n";
		cout << "---------------------------------------------------------" << endl;
	}
	}

}
