#pragma once
#include "Creature.h"

using namespace std;

class NPC :
    public Creature
{
public:
    NPC(string name, string description, Room* location) : Creature(EntityType::NPC, name, description, location) {
    };
};

