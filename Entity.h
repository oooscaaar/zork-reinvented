#pragma once

#include <string>
#include <list>

using namespace std;

enum EntityType {
	ROOM,
	EXIT,
	ITEM,
	PLAYER,
	NPC
};

class Entity 
{
public:
	Entity(EntityType type, const char* name, const char* description);
	~Entity();

private:
	EntityType type;
	string name;
	string description;
	list<Entity*> container;
};
