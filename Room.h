#pragma once
#include "Entity.h"
#include<vector>

class Exit;

class Room :
    public Entity
{
public:
	Room(string name, string description);

	vector<Exit*> GetExits();

};

