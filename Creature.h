#pragma once
#include "Entity.h"
#include "Room.h"

class Creature :
    public Entity
{

public:
    Creature(EntityType type, string name, string description, Room* location = nullptr): Entity(type, name, description) {
        this->location = location;
    };

    Room* location;
};



