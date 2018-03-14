#pragma once
#include "Entity.h"
#include "Room.h"


class Player : public Entity
{
private:
	Room* m_Location;
	Entity* GetItem(string name, bool remove);
	void Look(vector<string>& action);
	void Go(vector<string>& action);
	void Take(vector<string>& action);
	void Drop(vector<string>& action);
	void Inventory();
	void Open(vector<string>& action);
	void Close(vector<string>& action);
	void Unlock(vector<string>& action);
	void Lock(vector<string>& action);
	bool Sit();

public:
	Player(string name, string description, Room* room);
	bool PerformAction(vector<string>& action);
};
