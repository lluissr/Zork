#include "Room.h"


Room::Room(string name, string description): Entity(name, description)
{
	m_Type = ROOM;
}

void Room::Look()
{
	cout << "\n" << m_Name << "\n" << m_Description;
}