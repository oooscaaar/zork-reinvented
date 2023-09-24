#pragma once

#include <vector>
#include "Entity.h"

using namespace std;

class World
{
public:
	World();
	~World();
private:
	vector<Entity*> entities;
};

