#pragma once
#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "Entity.h"
#include "Player.h"

using namespace std;

class World
{

private:
	vector<Entity*> entities;
	Player* pPlayer;

public:
	World();
	void Run();
	void ExecuteAction(vector<string>& action);
};