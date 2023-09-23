#pragma once
#include "Entity.h"
#include "Room.h"

typedef enum DirectionType {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

class Exit :
	public Entity
{
private:
	DirectionType direction;
	Room* source;
	Room* destination;
};

