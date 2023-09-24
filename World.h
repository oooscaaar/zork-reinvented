#pragma once

#include <vector>
#include "Entity.h"

using namespace std;

enum class GameState {
	RUNNING,
	WIN,
	GAMEOVER
};

class World
{
public:
	World();
	~World();
	Entity* FindEntityByName(string name);
	Entity* FindEntityByType(EntityType type);
	GameState GetGameState();
	void HandleUserInput(vector<string>);

private:
	vector<Entity*> entities;
	GameState gameState;
};

