#include "Player.h"
#include "Utils.h"
#include <vector>

void Player::DisplayInventory() {
	cout << "\n----------------------- INVENTORY -----------------------\n" << endl;

	if (container.size() == 0) {
		cout << "Your inventory is empty." << endl;
	}
	else {
		for (Entity* e : container) {
			if (e->type == EntityType::ITEM) {
				cout << e->name << " - " << e->description << endl;
			}

		}
	}
	cout << "\n---------------------------------------------------------\n" << endl;

}

string Player::getLocationName() {
	return location->name;
}

void Player::Go(string& direction) {
	vector<Exit*> exitsInRoom = location->GetExits();
	for (Exit* e : exitsInRoom) {
		if (e->GetDirection() == direction) {
			//TODO: Add locked door mechanic (CHeck if door is locked, and If so, check player inventory and output a message accordingly.
			this->location = e->GetDestination();
		}
	}
}
