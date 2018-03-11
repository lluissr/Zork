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
		m_Location->Look();
	}
	//Go in a specific direction
	else if (action[0] == "go" || action[0] == "north" || action[0] == "east" || action[0] == "west" || action[0] == "south")
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
	//Get Item
	else if ((action[0] == "take" || action[0] == "get") && action.size() > 1)
	{
		Entity* item = m_Location->GetItem(action[1]);

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
	//Drop Item
	else if ((action[0] == "drop" || action[0] == "release") && action.size() > 1)
	{
		Entity* item = GetItem(action[1]);
		if (item == NULL)
		{
			cout << "You don't have " << action[1] << " in your inventory.\n";
		}
		else
		{
			m_Location->AddElementInRoom(item);
			cout << "Dropped.\n";
		}
	}
	else if (action[0] == "inventory")
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
	else
	{
		cout << "Incorrect command\n";
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