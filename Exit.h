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
	bool m_Closed;

public:
	Exit(string name, string description, Direction direction, Room* source, Room* destination, bool closed);
	void LookFromRoom(Room* room);
	string GetExitDirection(Room* room);
	Room* GetDestinationRoom(Room* room);
};

