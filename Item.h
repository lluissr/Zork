#pragma once
#include "Entity.h"
#include "Room.h"

class Room;

class Item : public Entity
{
private:
	bool m_IsOpen;
	bool m_Openable;
public:
	Item(string name, string description, Room* room, Item* container, bool openable, bool isOpen);
	void Look();
	void Open();
	void Close();
	bool IsOpen();
	Entity* GetContainingItem(string name);
};
