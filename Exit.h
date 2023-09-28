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
	Exit(string name, string description, DirectionType direction, Room* source, Room* destination, string onCrossedMessage) : Entity(EntityType::EXIT, name, description) {
		this->direction = direction;
		this->source = source;
		this->destination = destination;
		this->onCrossedMessage = onCrossedMessage;
	}

	string GetDirection();
	string GetOnCrossedMessage();
	Room* GetDestination();

private:
	DirectionType direction;
	Room* source;
	Room* destination;
	string onCrossedMessage;
};

