#include "Player.h"

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