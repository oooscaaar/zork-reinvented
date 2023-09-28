#pragma once
#include "Entity.h"

enum class ItemType {
    COMMON,
    HOLDER,
    KEY
};

class Item :
    public Entity
{
public:
    Item(string name, string description, vector<string> asciiArt, ItemType itemType = ItemType::COMMON, Entity* parent = NULL);

    vector<string> asciiArt;
    ItemType itemType;

};

