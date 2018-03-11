#pragma once
#include "Entity.h"
#include "Room.h"

class Room;

class Item : public Entity
{
public:
	Item(string name, string description, Room* room);
	void Look();
};
