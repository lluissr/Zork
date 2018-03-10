#pragma once
#include "Entity.h"

class Room : public Entity
{
private:

public:
	Room(string name, string description);
	void Look();
};
