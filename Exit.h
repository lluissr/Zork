#pragma once
#include "Entity.h"
#include "Room.h"

class Room;

enum Direction { NORTH, WEST, EAST, SOUTH };

class Exit : public Entity
{
private:
	Direction m_Direction;
	Room* m_Source;
	Room* m_Destination;
	bool m_IsOpen;
	bool m_IsLocked;
	bool m_IsLockable;

public:
	Exit(string name, string description, Direction direction, Room* source, Room* destination, bool open, bool locked, bool lockable);
	void Look(Room* room);
	string GetExitDirection(Room* room);
	Room* GetDestinationRoom(Room* room);
	bool IsOpen();
	bool Open();
	bool Close();
	bool Unlock();
	bool Lock();
};

