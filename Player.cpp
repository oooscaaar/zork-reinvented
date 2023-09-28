#include "Player.h"
#include "Utils.h"
#include <vector>

void Player::DisplayInventory() {
	cout << "// INVENTORY\n";

	if (container.size() == 0) {
		cout << "Your inventory is empty." << endl;
	}
	else {
		for (Entity* e : container) {
			if (e->type == EntityType::ITEM) {
				cout << Utils::ToUpper(e->name) << ": " << e->description << endl;
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
			//TODO: Add locked door mechanic (CHeck if door is locked, and If so, check player inventory and output a message accordingly.
			this->location = e->GetDestination();
		}
	}
}

//TODO: Debug this
void Player::Take(string itemName) {
	vector<Entity*> itemsInTheRoom = location->GetChildrenByType(EntityType::ITEM);
	if (itemsInTheRoom.empty()) {
		cout << "There is no such item in this room." << endl;
	}
	for (Entity* e : itemsInTheRoom) {
		if (e->name == Utils::ToLower(itemName) ) {
			this->Add(e);
			e->SetParent(this);
			cout << "You took a " << Utils::ToUpper(e->name) << endl;
		}
	}
	cout << "---------------------------------------------------------" << endl;
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
		cout << "You look around and see: \n";
		for (Entity* e : entitiesInTheRoom) {
			cout << Utils::ToUpper(e->name) << endl;
		}
	}
	cout << "---------------------------------------------------------" << endl;
}

void Player::Inspect(string entityName) {
	//TODO: Get Entity
	//TODO: Print entity description
}
