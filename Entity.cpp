#include "Entity.h"


Entity::Entity(EntityType type, string name, string description) {
	this->type = type;
	this->name = name;
	this->description = description;
	this->parent = nullptr;
}

Entity::~Entity() {}

void Entity::Add(Entity* entity) {
	entity->parent = this;
	container.push_back(entity);
}

void Entity::Remove(Entity* entity) {
	container.remove(entity);
}

list<Entity*> Entity::GetChildren() const {
	return container;
}

Entity* Entity::GetChildByName(string childName) {
	for (Entity* child : container) {
		if (Utils::ToLower(child->name) == childName) {
			return child;
		}
	}
	return nullptr;
}

vector<Entity*> Entity::GetChildrenByType(EntityType entityType) {
	vector<Entity*> filteredEntities;
	for (Entity* e : container) {
		if (e->type == entityType) {
			filteredEntities.push_back(e);
		}
	}
	return filteredEntities;
}

Entity* Entity::GetParent() const {
	return parent;
}

void Entity::SetParent(Entity* parent) {
	this->parent = parent;
}