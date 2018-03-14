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
	vector<Entity*> m_Entities;
	Player* pPlayer;
	int m_MaxNumberOfTurns = 30;
	int m_NumberOfTurnsPlayed = 0;
	bool m_Playing = true;
	void RestartGame();
	vector<string> GetTokens(string action);
	void PrepareEntitiesForNewGame();
	void AddIntroduction();

public:
	World();
	void Run();
	
};