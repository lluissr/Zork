#include "Room.h"


Room::Room(const string name, const string description) : Entity(name, description)
{
	m_Type = ROOM;
}


void Room::Look() const
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


Exit* Room::GetExit(const string direction) const
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


Entity* Room::GetItem(const string name, const bool remove)
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


Entity* Room::ExistItem(const string name) const
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == ITEM)
		{
			string itemName = entity->GetName();
			if (itemName == name)
			{
				return entity;
			}
		}
	}
	
	return NULL;
}

Entity* Room::ExistExit(const string name) const
{
	for each (Entity* entity in m_Contains)
	{
		if (entity->GetType() == EXIT)
		{
			string itemName = entity->GetName();
			if (itemName == name)
			{
				return entity;
			}
		}
	}

	return NULL;
}

void Room::OpenDoor() const
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


void Room::CloseDoor() const
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


void Room::UnlockDoor(Entity* key) const
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


void Room::LockDoor(Entity* key) const
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