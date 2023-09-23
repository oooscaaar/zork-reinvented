#include "item.h"

Item::Item(const char* name, const char* description, Entity* parent) : Entity(EntityType::ITEM, name, description) {}