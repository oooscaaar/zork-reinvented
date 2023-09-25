#include "Entity.h"


Entity::Entity(EntityType type, string name, string description) {
	this->type = type;
	this->name = name;
	this->description = description;
	this->parent = nullptr;
}

Entity::~Entity() {}

void Entity::Add(Entity* entity) {
	container.push_back(entity);
}

void Entity::Remove(Entity* entity) {
	container.remove(entity);
}

Entity* Entity::GetParent() const {
	return parent;
}

void Entity::SetParent(Entity* parent) {
	this->parent = parent;
}