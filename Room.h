#pragma once
#include "Entity.h"
#include<vector>
#include <string>

class Exit;

class Room :
    public Entity
{
public:
	Room(string name, string description, vector<string> asciiArt);

	vector<Exit*> GetExits();

	vector<string> asciiArt;
};

