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
	bool m_IsMovable;

public:
	Item(string name, string description, Room* room, Item* container, bool openable, bool isOpen, Exit* exit, bool movable);
	void Look();
	void Open();
	void Close();
	bool IsOpen();
	bool IsOpenable();
	bool IsMovable();
	Entity* GetContainingItem(string name);
};
