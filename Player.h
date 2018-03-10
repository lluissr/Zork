#pragma once
#include "Entity.h"
#include "Room.h"


class Player : public Entity
{
private:
	Room* m_Location;
public:
	Player(string name, string description, Room* room);
	bool PerformAction(vector<string>& action);
};
