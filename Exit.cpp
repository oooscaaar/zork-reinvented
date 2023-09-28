#include "Exit.h"

// Convert return type to string so consumers does no have to handle direction types
string Exit::GetDirection() {
	if (direction == DirectionType::NORTH) {
		return "north";
		
	}
	else if (direction == DirectionType::EAST) {
		return "east";
	}
	else if
		(direction == DirectionType::SOUTH) {
		return "south";
	}
	return "west";
}

Room* Exit::GetDestination() {
	return destination;
}

string Exit::GetOnCrossedMessage() {
	return this->onCrossedMessage;
}

bool Exit::IsLocked() {
	return this->isLocked;
}

void Exit::UnLock() {
	this->isLocked = false;
}

void Exit::Lock() {
	this->isLocked = true;
}
