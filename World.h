#pragma once

#include <vector>
#include "Entity.h"
#include "Player.h"

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
	void DisplayHelp();
	void DisplayAbout();

private:
	vector<Entity*> entities;
	GameState gameState;
	Player* player;
};

