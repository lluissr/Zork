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


void Room::AddElementInRoom(Entity* entity)
{
	m_Contains.push_back(entity);
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


Item* Room::GetItem(string name)
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == ITEM)
		{
			Item* pItem = (Item*)entity;
			string itemName = pItem->GetName();
			if (itemName == name)
			{
				m_Contains.remove(pItem);
				return pItem;
			}
		}
	}

	return NULL;
}