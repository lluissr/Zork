#pragma once
#include <string>
#include <list>
#include <iostream>
#include <vector>

using namespace std;


enum EntityType {ROOM, EXIT, PLAYER};


class Entity
{

protected:
	EntityType m_Type;
	string m_Name;
	string m_Description;
	list<Entity*> contains;

public:

	Entity(string name, string description);
	//virtual void Update();
};