#pragma once
#include "Creature.h"
#include "Exit.h"
#include "UI.h"
#include "Item.h"
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

    string getLocationName();

    void Go(string direction);
    void Take(string itemName);
    void Drop(string itemName);
    void Look();
    void Inspect(string entityName);

};

