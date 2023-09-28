#include "item.h"

Item::Item(const char* name, const char* description, vector<string> asciiArt, Entity* parent) : Entity(EntityType::ITEM, name, description) {
	this->asciiArt = asciiArt;
}