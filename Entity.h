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

	Entity* GetParent() const;
	void SetParent(Entity* parent);
	void Add(Entity* entity);
	void Remove(Entity* entity);

	Entity* parent;
	list<Entity*> container;
	EntityType type;
	string name;
	string description;
};
