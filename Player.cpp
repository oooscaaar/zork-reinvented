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

void Player::Go(string& direction) {
	// Check if there's a door pointing in that direction
	vector<Exit*> exitsInRoom = location->GetExits();
	for (Exit* e : exitsInRoom) {
		if (e->GetDirection() == direction) {
			this->location = e->GetDestination();

		}
		// Check if the door is locked
		// Go
	}
}
