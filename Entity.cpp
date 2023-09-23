#include "Entity.h"


Entity::Entity(EntityType type, const char* name, const char* description) {
	this->name = name;
	this->description = description;
	this->type = type;

}

Entity::~Entity() {}