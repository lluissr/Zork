#include "Room.h"


Room::Room(string name, string description): Entity(name, description)
{
	m_Type = ROOM;
}


void Room::Look()
{
	cout << "\n" << m_Name << "\n" << m_Description << ".";
	
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == EXIT)
		{
			Exit* pExit = (Exit*)entity;
			pExit->LookFromRoom(this);
		}
	}
}


void Room::AddElementInRoom(Entity* exit)
{
	m_Contains.push_back(exit);
}


Exit* Room::GetExit(string direction)
{
	if (direction == "north" || direction == "east" || direction == "west" || direction == "south")
	{
		for each (Entity* entity in m_Contains)
		{
			if (entity->GetType() == EXIT)
			{
				Exit* pExit = (Exit*)entity;
				string exitdirection = pExit->GetExitDirection(this);
				if (exitdirection == direction)
				{
					return pExit;
				}
			}
		}
	}
	else
	{
		cout << "This is not a valid direction.\n";
	}

	return NULL;
}


string Room::GetName()
{
	return m_Name;
}