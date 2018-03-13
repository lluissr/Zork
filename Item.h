#pragma once
#include "Entity.h"
#include "Room.h"

class Room;
class Exit;

class Item : public Entity
{
private:
	bool m_IsOpen;
	bool m_Openable;
public:
	Item(string name, string description, Room* room, Item* container, bool openable, bool isOpen, Exit* exit);
	void Look();
	void Open();
	void Close();
	bool IsOpen();
	bool IsOpenable();
	Entity* GetContainingItem(string name);
};
