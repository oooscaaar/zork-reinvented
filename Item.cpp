#include "item.h"

Item::Item(string name, string description, vector<string> asciiArt, ItemType itemType, Entity* parent) : Entity(EntityType::ITEM, name, description) {
	this->asciiArt = asciiArt;
	this -> parent = parent;
	this->itemType = itemType;
}