#pragma once
#include "Entity.h"
#include "Room.h"

enum class DirectionType {
	NORTH,
	EAST,
	SOUTH,
	WEST
};


class Exit :
	public Entity
{
public:
	Exit(string name, string description, DirectionType direction, Room* source, Room* destination, string onCrossedMessage, bool isLocked = false) : Entity(EntityType::EXIT, name, description) {
		this->direction = direction;
		this->source = source;
		this->destination = destination;
		this->onCrossedMessage = onCrossedMessage;
		this->isLocked = isLocked;
	}

	string GetDirection();
	string GetOnCrossedMessage();
	Room* GetDestination();
	bool IsLocked();
	void UnLock();
	void Lock();

private:
	DirectionType direction;
	Room* source;
	Room* destination;
	string onCrossedMessage;
	bool isLocked;
};

