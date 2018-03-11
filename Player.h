#pragma once
#include "Entity.h"
#include "Room.h"


class Player : public Entity
{
private:
	Room* m_Location;
	Entity* GetItem(string name);
	void Look(vector<string>& action);
	void Go(vector<string>& action);
	void Take(vector<string>& action);
	void Drop(vector<string>& action);
	void Inventory(vector<string>& action);
	void Open(vector<string>& action);
	void Close(vector<string>& action);
public:
	Player(string name, string description, Room* room);
	void PerformAction(vector<string>& action);
};
