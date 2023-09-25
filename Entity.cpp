#include "Entity.h"


Entity::Entity(EntityType type, string name, string description) {
	this->type = type;
	this->name = name;
	this->description = description;
	this->parent = nullptr;
}

Entity::~Entity() {}


// TODO: Change argument type to string and handle find entity withing the class, not within the whole world.
void Entity::Add(Entity* entity) {
	entity->parent = this;
	container.push_back(entity);
}

// TODO: Change argument type to string and handle find entity withing the class, not within the whole world.
void Entity::Remove(Entity* entity) {
	// Early return if entity is not owned
	if (entity->parent != this) {
		return;
	}
	// Set parent one level up if it exists
	if (entity->parent->parent != NULL) {
		entity->parent = entity->parent->parent;
		entity->parent->parent->container.push_back(entity);
	}
	container.remove(entity);
}

Entity* Entity::GetParent() const {
	return parent;
}

void Entity::SetParent(Entity* parent) {
	this->parent = parent;
}