#pragma once

#include <vector>
#include "Entity.h"

using namespace std;

class World
{
public:
	World();
	~World();
	Entity* FindEntityByName(string name);
	Entity* FindEntityByType(EntityType type);

private:
	vector<Entity*> entities;
};

