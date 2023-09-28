#pragma once

#include <string>
#include <list>
#include <vector>
#include "Utils.h"

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
	list<Entity*> GetChildren() const;
	vector<Entity*> GetChildrenByType(EntityType entityType);
	Entity* GetChildByName(string childName);
	void SetParent(Entity* parent);
	void Add(Entity* entity);
	void Remove(Entity* entity);

	Entity* parent;
	list<Entity*> container;
	EntityType type;
	string name;
	string description;
};
