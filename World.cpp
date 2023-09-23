#include "World.h"
#include "Room.h"
#include "Item.h"

World::World() {

	// Rooms
	Room* facilities_entrance = new Room("NASA Facilities", "You are talking to a guard. He asks for an ID card in order to let you pass the security check and access to the NASA building. \n\nType HELP to get a list of available commands.");
	Room* hall = new Room("Main Hall", "The guard lets you access the building. You are in the main hall. It's quite a big building. Luckily you took a MAP so you can get to your office.");
	Room* hubble_telescope_room = new Room("Hubble Telescope Room", "Finally, you mange to access the room.You see a huge TELESCOPE in the middle of the chamber.You are full of confidence, you can save the world.");
	Room* quantum_computer_room = new Room("Quantum Computer Room", "Let's crack some cyphered secrets");
	Room* players_office = new Room("Your Office", "This is your humble office. It's equiped with a COMPUTER, a desk and a huge american FLAG on the wall.");

	//
	Item* map = new Item("Map", "Map of the building", hall);
}

World::~World() {
	
}