#include "Room.h"

Room::Room(string name, string description) : Entity(EntityType::ROOM, name, description) {
	this->name = name;
	this->description = description;
}

vector<Exit*> Room::GetExits() {
	//TODO: Implement method
	return (vector < Exit*>)0;
};

