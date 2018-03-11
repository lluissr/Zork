#pragma once
#include "Entity.h"
#include "Room.h"


class Player : public Entity
{
private:
	Room* m_Location;
	Entity* GetItem(string name);
public:
	Player(string name, string description, Room* room);
	void PerformAction(vector<string>& action);
};
