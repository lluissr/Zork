#include "Exit.h"


Exit::Exit(string name, string description, Direction direction, Room* source , Room* destination, bool open, bool locked, bool lockable) :Entity(name, description)
{
	m_Type = EXIT;
	m_Direction = direction;
	m_Source = source;
	m_Destination = destination;
	m_IsOpen = open;
	m_IsLocked = locked;
	m_IsLockable = lockable;

	m_Source->AddEntity(this);
	m_Destination->AddEntity(this);
}


void Exit::Look(Room* room)
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


bool Exit::IsOpen()
{
	return m_IsOpen;
}


bool Exit::Open()
{
	if (m_Name == "door")
	{
		if (m_IsOpen)
		{
			cout << "The door is already open";
			return true;
		}
		else if (m_IsLocked)
		{
			cout << "The door is locked. It seems that you need a key.";
			return true;
		}
		else
		{
			m_IsOpen = true;
			cout << "You open the door.";
			return true;
		}
	}
	else
	{
		return false;
	}
}


bool Exit::Close()
{
	if (m_Name == "door")
	{
		if (m_IsOpen)
		{
			m_IsOpen = false;
			cout << "You close the door";
			return true;
		}
		else
		{
			cout << "The door is already closed.";
			return true;
		}
	}
	else
	{
		return false;
	}
}