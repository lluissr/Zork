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
		m_Location->Look();
		return true;
	}
	//Go in a specifiv direction
	else if (action[0] == "go" || action[0] == "north" || action[0] == "east" || action[0] == "west" || action[0] == "south")
	{
		if (action[0] == "go" && action.size() > 1)
		{
			action[0] = action[1];
		}

		Exit* exit = m_Location->GetExit(action[0]);
		
		if (exit == NULL)
		{
			cout << "There is no exit at " << action[0];
			return true;
		}
		else
		{
			m_Location = exit->GetDestinationRoom(m_Location);
			cout << "You take the exit and you get to the " << m_Location->GetName() << "\n";
			m_Location->Look();
			return true;
		}
	}
	else
	{
		return false;
	}
}