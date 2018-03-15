#pragma once
#include <string>
#include <list>
#include <iostream>
#include <vector>

using namespace std;


enum EntityType {ROOM, EXIT, PLAYER, ITEM};


class Entity
{

protected:
	EntityType m_Type;
	string m_Name;
	string m_Description;
	list<Entity*> m_Contains;

public:

	Entity(const string name, const string description);
	virtual void Look() const = 0;
	EntityType GetType() const;
	string GetName() const;
	string GetDescription() const;
	void AddEntity(Entity* entity);
};