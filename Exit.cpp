#include "Exit.h"


Exit::Exit(string name, string description, Direction direction, Room* source , Room* destination, bool closed) :Entity(name, description)
{
	m_Type = EXIT;
	m_Direction = direction;
	m_Source = source;
	m_Destination = destination;
	m_Closed = closed;

	m_Source->AddEntity(this);
	m_Destination->AddEntity(this);
}


void Exit::LookFromRoom(Room* room)
{
	cout << "\nThere is a " << m_Name << " " << m_Description << " in the " << GetExitDirection(room) << " part of the room.";
}

string Exit::GetExitDirection(Room* room)
{
	bool fromSource = room == m_Source;

	switch (m_Direction)
	{
	case NORTH:
		return fromSource ? "north" : "south";
	case SOUTH:
		return fromSource ? "south" : "north";
	case EAST:
		return fromSource ? "east" : "west";
	case WEST:
		return fromSource ? "west" : "east";
	}
	return "";
}


Room* Exit::GetDestinationRoom(Room* room)
{
	if (room == m_Source)
	{
		return m_Destination;
	}
	else
	{
		return m_Source;
	}
}