#pragma once
#include "Entity.h"
#include "Exit.h"

class Exit;

class Room : public Entity
{
public:
	Room(string name, string description);
	void Look();
	void AddElementInRoom(Entity* exit);
	Exit* GetExit(string direction);
	string GetName();
};
