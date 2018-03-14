#include "Player.h"


Player::Player(string name, string description, Room* room) :Entity(name, description)
{
	m_Type = PLAYER;
	m_Location = room;
}


bool Player::PerformAction(vector<string>& action)
{

	//Look something
	if (action[0] == "look")
	{
		Look(action);
	}
	//Go in a specific direction
	else if (action[0] == "go" || action[0] == "north" || action[0] == "east" || action[0] == "west" || action[0] == "south")
	{
		Go(action);
	}
	//Get Item
	else if ((action[0] == "take" || action[0] == "get" || action[0] == "pick") && action.size() > 1)
	{
		Take(action);
	}
	//Drop Item
	else if ((action[0] == "drop" || action[0] == "release" || action[0] == "put") && action.size() > 1)
	{
		Drop(action);
	}
	//Check inventory
	else if (action[0] == "inventory")
	{
		Inventory();
	}
	//Open Objects
	else if (action[0] == "open" && action.size() > 1)
	{
		Open(action);
	}
	//Close Objects
	else if (action[0] == "close" && action.size() > 1)
	{
		Close(action);
	}
	//UnLook door with item
	else if (action[0] == "unlock" && action.size() > 3)
	{
		Unlock(action);
	}
	//Look door with item
	else if (action[0] == "lock" && action.size() > 3)
	{
		Lock(action);
	}
	else if (action[0] == "sit" )
	{
		return Sit();
	}
	//Incorrect action
	else
	{
		cout << "I don't understand this action\n";
	}
	return false;
}


//--Private Methods


void Player::Look(vector<string>& action)
{
	//Look arround
	if (action.size() == 1)
	{
		m_Location->Look();
	}
	//Look specific object
	else if (action.size() > 1)
	{
		Entity* entity = GetItem(action[1], false);

		if (entity == NULL) {
			entity = m_Location->ExistItem(action[1]);
		}

		if (entity != NULL)
		{
			Item* item = (Item*)entity;
			item->Look();
		}
	}
}


void Player::Go(vector<string>& action)
{
	if (action[0] == "go" && action.size() > 1)
	{
		action[0] = action[1];
	}

	if (action[0] == "north" || action[0] == "east" || action[0] == "west" || action[0] == "south")
	{

		Exit* exit = m_Location->GetExit(action[0]);

		if (exit == NULL)
		{
			cout << "There is no exit at " << action[0];
		}
		else
		{
			if (exit->IsOpen())
			{
				m_Location = exit->GetDestinationRoom(m_Location);
				cout << "You take the exit and you get to the " << m_Location->GetName() << "\n";
				m_Location->Look();
			}
			else
			{
				cout << "The door is closed";
			}
		}
	}
	else
	{
		cout << "This is not a valid direction.\n";
	}
}


void Player::Take(vector<string>& action)
{
	Entity* item = m_Location->GetItem(action[1], true);

	if (item != NULL)
	{
		m_Contains.push_back(item);
		cout << "Taken.\n";
	}
}


void Player::Drop(vector<string>& action)
{
	//Drop something into room
	if (action.size() == 2)
	{
		Entity* item = GetItem(action[1], true);
		if (item == NULL)
		{
			cout << "You don't have " << action[1] << " in your inventory.\n";
		}
		else
		{
			m_Location->AddEntity(item);
			cout << "Dropped.\n";
		}
	}
	//Drop something into something
	else if (action.size() == 4)
	{
		if (action[1] != action[3]) 
		{
			Entity* playerItem = GetItem(action[1], false);
			if (playerItem == NULL)
			{
				cout << "You don't have " << action[1] << " in your inventory.\n";
				return;
			}

			Entity* containerItem = NULL;
			containerItem = GetItem(action[3], false);

			if (containerItem == NULL) {
				Entity* roomEntity = m_Location->GetItem(action[3], false);

				if (roomEntity == NULL)
				{
					cout << "There is no " << action[3] << " in the room or in your inventory.";
					return;
				}
				containerItem = roomEntity;
			}

			Item* item = (Item*)containerItem;
			if (item->IsOpenable())
			{
				if (item->IsOpen())
				{
					containerItem->AddEntity(playerItem);
					m_Contains.remove(playerItem);
					cout << "You put the " << action[1] << " into the " << action[3] << ".";
				}
				else
				{
					cout << "The " << action[3] << " is closed. Open it first.";
				}
			} 
			else
			{
				cout << "You can't put anything inside " << action[3] << ".";
			}
		}
		else 
		{
			cout << "You can't put an object inside himself. Are you crazy?";
		}
	}
}


void Player::Inventory()
{
	if (m_Contains.size() == 0)
	{
		cout << "Your inventory is empty";
	}
	else
	{
		cout << "You are carrying:";
		for each (Entity* entity in m_Contains)
		{
			if (entity->GetType() == ITEM)
			{
				cout << "\n" << entity->GetName() << ": " << entity->GetDescription();
			}
		}
	}
}


void Player::Open(vector<string>& action)
{
	if (action[1] != "door")
	{
		Entity* entity = GetItem(action[1], false);

		if (entity == NULL) {
			entity = m_Location->ExistItem(action[1]);
		}

		if (entity != NULL)
		{
			Item* item = (Item*)entity;
			item->Open();
		}
	}
	else
	{
		m_Location->OpenDoor();
	}
}


void Player::Close(vector<string>& action)
{
	if (action[1] != "door")
	{

		Entity* entity = GetItem(action[1], false);

		if (entity == NULL) {
			entity = m_Location->ExistItem(action[1]);
		}

		if (entity != NULL)
		{
			Item* item = (Item*)entity;
			item->Close();
		}
	}
	else
	{
		m_Location->CloseDoor();
	}
}


void Player::Unlock(vector<string>& action)
{
	Entity* playerItem = GetItem(action[3], false);
	if (playerItem == NULL)
	{
		cout << "You don't have " << action[3] << " in your inventory.\n";
		return;
	}


	m_Location->UnlockDoor(playerItem);
}


void Player::Lock(vector<string>& action)
{
	Entity* playerItem = GetItem(action[3], false);
	if (playerItem == NULL)
	{
		cout << "You don't have " << action[3] << " in your inventory.\n";
		return;
	}

	m_Location->LockDoor(playerItem);
}


bool Player::Sit()
{
	if (m_Location->GetName() == "Bathroom")
	{
		Entity* toilet = m_Location->ExistItem("toilet");
		if (((Item*)toilet)->IsOpen())
		{
			if (GetItem("paper", false) != NULL)
			{
				cout << "You sit in the toilet and finally rest calmly.";
				return true;
			}
			else
			{
				cout << "You have to find paper before sit or it will be a mess later.";
			}
		}
		else
		{
			cout << "Open the toilet before sit.";
		}
	}
	else
	{
		cout << "You are not in the bathroom. You can't sit or it will be impossible to get up again.";
	}

	return false;
}


Entity* Player::GetItem(string name, bool remove)
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == ITEM)
		{
			string itemName = entity->GetName();
			if (itemName == name)
			{
				if (remove)
				{
					m_Contains.remove(entity);
				}
				return entity;
			}
		}
	}

	return NULL;
}