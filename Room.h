#pragma once
#include "Entity.h"
#include "Exit.h"
#include "Item.h"

class Exit;
class Item;

class Room : public Entity
{
public:
	Room(string name, string description);
	void Look();
	void AddElementInRoom(Entity* exit);
	Exit* GetExit(string direction);
	Item* GetItem(string itemName);
};
