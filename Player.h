#pragma once
#include "Creature.h"
#include<iostream>

using namespace std;

class Player :
    public Creature
{
public: 
    Player(string name, string description, Room* location) : Creature(EntityType::PLAYER, name, description, location) {
    };

    void SetName(string name) {
        this->name = name;
    };

    void DisplayInventory();

    void Go(string direction);

};

