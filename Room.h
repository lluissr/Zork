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
	Exit* GetExit(string direction);
	Entity* GetItem(string itemName, bool remove);
	void OpenDoor();
	void CloseDoor();
	void UnlockDoor(Entity* key);
	void LockDoor(Entity* key);
};
