#include "Item.h"


Item::Item(string name, string description, Room* room, Item* container, bool openable, bool isOpen, Exit* exit) :Entity(name, description)
{
	m_Type = ITEM;
	m_IsOpen = isOpen;
	m_Openable = openable;
	if (room != NULL)
	{
		room->AddEntity(this);
	}
	if (container != NULL)
	{
		container->AddEntity(this);
	}
	if (exit != NULL)
	{
		exit->AddEntity(this);
	}
}


void Item::Look()
{
	cout << "\nThere is a " << m_Name << " " << m_Description;
	if (m_Contains.size() > 0 && m_IsOpen)
	{
		cout << "\nThe " << m_Name << " is open:";
		for each (Entity* entity in m_Contains)
		{
			Item* item = (Item*)entity;
			item->Look();
		}
	}
}


void Item::Open()
{
	if (m_Openable)
	{
		if (m_IsOpen)
		{
			cout << "It's already open.";
		}
		else
		{
			m_IsOpen = true;
			cout << "You open the " << m_Name;
			for each (Entity* entity in m_Contains)
			{
				Item* item = (Item*)entity;
				item->Look();
			}
		}
	}
	else
	{
		cout << "You can't open this";
	}
}


void Item::Close()
{
	if (m_Openable)
	{
		if (m_IsOpen)
		{
			m_IsOpen = false;
			cout << "You close the " << m_Name;
		}
		else
		{
			cout << "It's already close.";
		}
	}
	else
	{
		cout << "You can't close this";
	}
}


bool Item::IsOpen()
{
	return m_IsOpen;
}


bool Item::IsOpenable()
{
	return m_Openable;
}


Entity* Item::GetContainingItem(string name)
{
	if (m_Openable && m_IsOpen)
	{
		for each (Entity* entity in m_Contains)
		{
			if (entity->GetType() == ITEM && entity->GetName() == name)
			{
				m_Contains.remove(entity);
				return entity;
			}
		}
	}

	return NULL;
}
