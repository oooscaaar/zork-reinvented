#include "Room.h"
#include "UI.h"

Room::Room(string name, string description, vector<string> asciiArt) : Entity(EntityType::ROOM, name, description) {
	this->name = name;
	this->description = description;
	this-> asciiArt = asciiArt;
}

vector<Exit*> Room::GetExits() {
	vector<Exit*> exitsInRoom;
	for (Entity* e : container) {
		if (e->type == EntityType::EXIT) {
			exitsInRoom.push_back((Exit*)e);
		}
	}
	return exitsInRoom;
};

