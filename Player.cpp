#include "Player.h"

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
		if (Utils::ToLower(e->GetDirection()) == Utils::ToLower(direction)) {
			if (e->IsLocked()) {
				if (location->name == "Main Hall" && e->GetDirection() == "west") {
					UI::DisplayAscii(AsciiArt::accessCodeTerminal);
					cout << "ACCESS RESTRICTED - Please insert code:\n> ";
					string code;
					while (code.empty()) {
						getline(cin >> ws, code);
					}
					if (code == "1234") {
						e->UnLock();
						cout << "Nice! now you can go ahead!" << endl;
					}
					else {
						cout << "Nice try, but... INCORRECT CODE!\n---------------------------------------------------------" << endl;
					}
				}
				else {
					cout << "This door is locked. You'll need to find a way to open it.\n---------------------------------------------------------" << endl;
				}
			}
			else {
				this->location = e->GetDestination();
				UI::DisplayAscii(location->asciiArt);
				cout << e->GetOnCrossedMessage() << endl;
				cout << "\n---------------------------------------------------------" << endl;
			}
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
		if (entityToInspect->type == EntityType::ITEM) {
			Item* item = (Item*)entityToInspect;
			UI::DisplayAscii(item->asciiArt);
		}
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
		// Unlock Facilites entrance door with ID Card.
		if (itemToUse->name == "id") {
			if (location->name == "NASA Facilities Entrance") {
				vector<Exit*> exitsInLocation = location->GetExits();
				for (Exit* e : exitsInLocation) {
					if (e->GetDirection() == "north") {
						e->UnLock();
						cout << "Nice! now you can go ahead!" << endl;
					}
				}
			}
		}
		else if (itemToUse->name == "laptop") {
			cout << "You boot the computer and check your email inbox.\nYou have an email from the NASA Chief Scientist. \nYou start reading and...\nWTF*CK!!!\n\"The planet earth is at risk! Accoording to the predictions, some large asteroids are approaching to our planet!\"\nIn the mail, the NASA Chief Scientist sent you a CODE, so you can access the Hubble telescope room and then investigate what is really happening.\nYou note the CODE on a paper, put it on your pocket, and poweroff the computer." << endl;
			//TODO: Add ascii art with the code.
			Item* code = new Item("code", "Secret access code to the hubble telescope room.", AsciiArt::code);
			this->Add(code);
		}
		else if (itemToUse->name == "map") {
			this->Inspect("map");
		} else if(itemToUse->name == "code"){
			cout << "You can't use the CODE. Maybe you should try inspecting..." << endl;
		}
	}
	else {
		cout << "There is no such item in your inventory." << endl;
	}
	cout << "---------------------------------------------------------" << endl;
}
