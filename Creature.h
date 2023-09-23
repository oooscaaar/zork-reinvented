#pragma once
#include "Entity.h"
#include "Room.h"

class Creature :
    public Entity
{

public:
    Room* location;

};

