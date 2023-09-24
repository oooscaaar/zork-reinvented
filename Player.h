#pragma once
#include "Creature.h"

class Player :
    public Creature
{
public: 
    Player(string name, string description, Room* location) : Creature(EntityType::PLAYER, name, description, location) {
    };

    void setName(string name) {
        this->name = name;
    }
};

