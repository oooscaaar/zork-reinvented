#pragma once

#include <vector>
#include "Entity.h"
#include "Room.h"

using namespace std;

class World
{
public:
	World();
	~World();
private:
	vector<Room*> entities;
};

