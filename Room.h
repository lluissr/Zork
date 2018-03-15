#pragma once
#include "Entity.h"
#include "Exit.h"
#include "Item.h"

class Exit;
class Item;

class Room : public Entity
{
public:
	Room(const string name, const string description);
	void Look() const;
	Exit* GetExit(const string direction) const;
	Entity* GetItem(const string itemName, const bool remove);
	Entity* ExistItem(const string itemName) const;
	Entity* ExistExit(const string exitName) const;
	void OpenDoor() const;
	void CloseDoor() const;
	void UnlockDoor(Entity* key) const;
	void LockDoor(Entity* key) const;
};
