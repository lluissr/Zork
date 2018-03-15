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
	Item(const string name, const string description, Room* room, Item* container, bool openable, bool isOpen, Exit* exit, bool movable);
	void Look() const;
	void Open();
	void Close();
	bool IsOpen() const;
	bool IsOpenable() const;
	bool IsMovable() const;
	Entity* GetContainingItem(string name);
};
