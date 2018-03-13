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
			pExit->Look(this);
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
				if (((Item*)entity)->IsMovable())
				{
					if (remove)
					{
						m_Contains.remove(entity);
					}
					return entity;
				}
				else
				{
					cout << "You can't carry this";
					return NULL;
				}
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
	cout << "There is not " << name << ".\n";
	return NULL;
}


void Room::OpenDoor()
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == EXIT)
		{
			Exit* pExit = (Exit*)entity;
			if (pExit->Open())
			{
				return;
			}
		}
	}

	cout << "There is no door in the room that can be open";
}


void Room::CloseDoor()
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == EXIT)
		{
			Exit* pExit = (Exit*)entity;
			if (pExit->Close())
			{
				return;
			}
		}
	}
	cout << "There is no door in the room that can be closed";
}


void Room::UnlockDoor(Entity* key)
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == EXIT)
		{
			Exit* pExit = (Exit*)entity;
			if (pExit->Unlock(key))
			{
				return;
			}
		}
	}
	cout << "There is no door in the room that can be unlock with " << key->GetName() << ".";
}


void Room::LockDoor(Entity* key)
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == EXIT)
		{
			Exit* pExit = (Exit*)entity;
			if (pExit->Lock(key))
			{
				return;
			}
		}
	}
	cout << "There is no door in the room that can be lock " << key->GetName() << ".";
}