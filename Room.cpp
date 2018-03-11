#include "Room.h"


Room::Room(string name, string description) : Entity(name, description)
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

	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == ITEM)
		{
			Item* pItem = (Item*)entity;
			pItem->Look();
		}
	}
}


Exit* Room::GetExit(string direction)
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == EXIT)
		{
			Exit* pExit = (Exit*)entity;
			string exitDirection = pExit->GetExitDirection(this);
			if (exitDirection == direction)
			{
				return pExit;
			}
		}
	}

	return NULL;
}


Entity* Room::GetItem(string name, bool remove)
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
			else
			{
				Item* item = (Item*)entity;
				Entity* insideItem = item->GetContainingItem(name);
				if (insideItem != NULL)
				{
					return insideItem;
				}
			}
		}
	}

	return NULL;
}