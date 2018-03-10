#pragma once
#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

class World
{

private:
	//TODO


public:
	World();
	void Run();
	bool ExecuteCommand(vector<string>& command);
};