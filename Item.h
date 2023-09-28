#pragma once
#include "Entity.h"

class Item :
    public Entity
{
public:
    Item(const char* name, const char* description, vector<string> asciiArt, Entity* parent = NULL);

    vector<string> asciiArt;

};

