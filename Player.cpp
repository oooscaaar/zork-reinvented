#include "Player.h"

using namespace std;

void Player::DisplayInventory() {
	cout << "// INVENTORY\n";

	if (container.size() == 0) {
		cout << "Your inventory is empty." << endl;
	}
	else {
		for (Entity* e : container) {
			if (e->type == EntityType::ITEM) {
				cout << "* " << Utils::ToUpper(e->name) << endl;
			}

		}
	}
	cout << "---------------------------------------------------------" << endl;
}

string Player::getLocationName() {
	return location->name;
}

void Player::Go(string direction) {
	vector<Exit*> exitsInRoom = location->GetExits();
	for (Exit* e : exitsInRoom) {
		if (e->GetDirection() == direction) {
			//TODO: Add locked door mechanic (Check if door is locked, and If so, check player inventory and output a message accordingly.
			this->location = e->GetDestination();
			UI::DisplayAscii(location->asciiArt);
			cout << e->GetOnCrossedMessage() << endl;
			cout << "\n---------------------------------------------------------" << endl;
		}
	}
}

void Player::Take(string itemName) {
	vector<Entity*> itemsInTheRoom = location->GetChildrenByType(EntityType::ITEM);
	if (itemsInTheRoom.empty()) {
		cout << "There is no such item in this room.\n---------------------------------------------------------" << endl;
		return;
	}
	for (Entity* e : itemsInTheRoom) {
		if (e->name == Utils::ToLower(itemName)) {
			this->Add(e);
			e->SetParent(this);
			location->Remove(e);
			cout << "You took a " << Utils::ToUpper(e->name) << "\n---------------------------------------------------------"<< endl;
			return;
		}
	}
	cout << "You can't take " << itemName << "\n---------------------------------------------------------" << endl;
}

void Player::Drop(string itemName) {
	Entity* entityToDrop = GetChildByName(Utils::ToLower(itemName));
	if (entityToDrop != nullptr) {
		location->Add(entityToDrop);
		container.remove(entityToDrop);
		cout << "You dropped the " << Utils::ToUpper(entityToDrop->name) << endl;
	}
	else {
		cout << "There is no such item in your inventory." << endl;
	}
	cout << "---------------------------------------------------------" << endl;
}

void Player::Look() {
	list<Entity*> entitiesInTheRoom = location->GetChildren();
	if (entitiesInTheRoom.empty()) {
		cout << "There's nothing interesting in this room." << endl;
	}
	else {
		cout << "You look around "<< location->name << " and you see:\n";
		for (Entity* e : entitiesInTheRoom) {
			if (e->type == EntityType::ITEM) {
				cout << "* " << Utils::ToUpper(e->name) << endl;
			}
			else {
				cout <<Utils::ToUpper(e->name) << endl;
			}

		}
	}
	cout << "---------------------------------------------------------" << endl;
}

void Player::Inspect(string entityName) {
	Entity* entityToInspect = nullptr;

	for(Entity* e: container) {
		if (e->name == Utils::ToLower(entityName)) {
			entityToInspect = e;
		}
	}

	if (entityToInspect == nullptr) {
		for (Entity* e : location->GetChildren()) {
			if (e->name == Utils::ToLower(entityName)) {
				entityToInspect = e;
			}
		}
	}

	if (entityToInspect != nullptr) {
		cout << Utils::ToUpper(entityToInspect->name) << ": " << entityToInspect->description << endl;
	}
	else {
		cout << "There is no " << Utils::ToUpper(entityName) << " around." << endl;
	}
	cout << "---------------------------------------------------------" << endl;
}

void Player::Use(string itemName) {
	Entity* itemToUse = GetChildByName(Utils::ToLower(itemName));
	//TODO: I wish I had more time so I could refactor this hadoken-spaghetti code.
	if (itemToUse != nullptr) {
		if (itemToUse->name == "id") {
			if (location->name == "NASA Facilities Entrance") {
				
			}
		}
	}
	else {
		cout << "There is no such item in your inventory." << endl;
	}
	cout << "---------------------------------------------------------" << endl;
}
