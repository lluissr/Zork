#include "Item.h"


Item::Item(string name, string description, Room* room) :Entity(name, description)
{
	m_Type = ITEM;
	room->AddElementInRoom(this);
}


void Item::Look()
{
	cout << "\nThere is a " << m_Name << " " << m_Description;
}