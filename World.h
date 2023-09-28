#pragma once

#include <vector>
#include "Entity.h"
#include "Player.h"

using namespace std;

class World
{
public:
	World();
	~World();
	Entity* FindEntityByName(string name);
	Entity* FindEntityByType(EntityType type);
	bool IsGameOver();
	void HandleUserInput(vector<string>);

private:
	vector<Entity*> entities;
	Player* player;
	bool isGameOver;
};

