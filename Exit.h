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
	Exit(const string name, const string description, Direction direction, Room* source, Room* destination, bool open, bool locked, bool lockable);
	void Look(const Room* room) const;
	void Look() const;
	string GetExitDirection(const Room* room) const;
	Room* GetDestinationRoom(const Room* room) const;
	bool IsOpen();
	bool Open();
	bool Close();
	bool Unlock(Entity* key);
	bool Lock(Entity* key);
};

