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
	else if ((action[0] == "drop" || action[0] == "release") && action.size() > 1)
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
	m_Location->Look();
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
	Entity* item = GetItem(action[1]);
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
	bool found = false;
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == ITEM)
		{
			string itemName = entity->GetName();
			if (itemName == action[1])
			{
				Item* item = (Item*)entity;
				item->Open();
				found = true;
			}
		}
	}

	Entity* roomEntity = m_Location->GetItem(action[1], false);
	if (roomEntity != NULL)
	{
		Item* roomItem = (Item*)roomEntity;
		roomItem->Open();
		found = true;
	}

	if (!found)
	{
		cout << "There is not " << action[1] << " in the room or in your inventory.";
	}
}


void Player::Close(vector<string>& action)
{
	bool found = false;
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == ITEM)
		{
			string itemName = entity->GetName();
			if (itemName == action[1])
			{
				Item* item = (Item*)entity;
				item->Close();
				found = true;
			}
		}
	}

	Entity* roomEntity = m_Location->GetItem(action[1], false);
	if (roomEntity != NULL)
	{
		Item* roomItem = (Item*)roomEntity;
		roomItem->Close();
		found = true;
	}

	if (!found)
	{
		cout << "There is not " << action[1] << " in the room or in your inventory.";
	}
}


Entity* Player::GetItem(string name)
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == ITEM)
		{
			string itemName = entity->GetName();
			if (itemName == name)
			{
				m_Contains.remove(entity);
				return entity;
			}
		}
	}

	return NULL;
}