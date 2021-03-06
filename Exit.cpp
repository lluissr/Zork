#include "Exit.h"


Exit::Exit(const string name, const string description, Direction direction, Room* source , Room* destination, bool open, bool locked, bool lockable) :Entity(name, description)
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


void Exit::Look(const Room* room) const
{
	cout << "\nThere is a " << m_Name << " " << m_Description << " in the " << GetExitDirection(room) << " part of the room.";
}


void Exit::Look() const
{
	cout << "\nThere is a " << m_Name << " " << m_Description << " in the room.";
}


string Exit::GetExitDirection(const Room* room) const
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


Room* Exit::GetDestinationRoom(const Room* room) const
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
			cout << "The door is locked. It seems that you need a " << m_Contains.front()->GetName() << ".";
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


bool Exit::Unlock(Entity* key)
{
	if (m_IsLockable && (find(m_Contains.begin(), m_Contains.end(), key) != m_Contains.end()))
	{
		if (m_IsLocked)
		{
			m_IsLocked = false;
			cout << "You unlock the door";
			return true;
		}
		else
		{
			cout << "The door is already unlocked.";
			return true;
		}
	}
	return false;
}


bool Exit::Lock(Entity* key)
{
	if (m_IsLockable && (find(m_Contains.begin(), m_Contains.end(), key) != m_Contains.end()))
	{
		if (m_IsLocked)
		{
			cout << "The door is already locked.";
			return true;
		}
		else
		{
			m_IsLocked = true;
			m_IsOpen = false;
			cout << "You lock the door";
			return true;
		}
	}
	return false;
}