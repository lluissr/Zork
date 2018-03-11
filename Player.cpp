#include "Player.h"


Player::Player(string name, string description, Room* room) :Entity(name, description)
{
	m_Type = PLAYER;
	m_Location = room;
}


void Player::PerformAction(vector<string>& action)
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
	else if ((action[0] == "take" || action[0] == "get") && action.size() > 1)
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
		Inventory(action);
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
	//Incorrect action
	else
	{
		cout << "Incorrect command\n";
	}
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
			entity = m_Location->GetItem(action[1], false);
		}

		if (entity == NULL)
		{
			cout << "There is no " << action[1] << ".";
		}
		else
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
			m_Location = exit->GetDestinationRoom(m_Location);
			cout << "You take the exit and you get to the " << m_Location->GetName() << "\n";
			m_Location->Look();
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

	if (item == NULL)
	{
		cout << "There is not " << action[1] << ".\n";
	}
	else
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
}


void Player::Inventory(vector<string>& action)
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
	Entity* entity = GetItem(action[1], false);
	
	if (entity == NULL) {
		entity = m_Location->GetItem(action[1], false);
	}

	if (entity == NULL)
	{
		cout << "There is no " << action[1] << " in the room or in your inventory.";
	}
	else
	{
		Item* item = (Item*)entity;
		item->Open();
	}
}


void Player::Close(vector<string>& action)
{
	Entity* entity = GetItem(action[1], false);

	if (entity == NULL) {
		entity = m_Location->GetItem(action[1], false);
	}

	if (entity == NULL)
	{
		cout << "There is no " << action[1] << " in the room or in your inventory.";
	}
	else
	{
		Item* item = (Item*)entity;
		item->Close();
	}
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