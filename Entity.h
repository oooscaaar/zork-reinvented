#pragma once

#include <string>
#include <list>

using namespace std;

enum class EntityType {
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER,
	NPC
};

class Entity 
{
public:
	Entity(EntityType type, string name, string description);
	~Entity();

	Entity* parent;
	list<Entity*> container;
	EntityType type;
	string name;
	string description;
};
