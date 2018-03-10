#include "World.h"


World::World()
{
	Room* pEntrance = new Room("Entrance", "Empty room with one chair");

	entities.push_back(pEntrance);

	pPlayer = new Player("Pepe", "Person", pEntrance);

	entities.push_back(pPlayer);
}


void World::Run()
{
	cout << "Welcome to Zork\n\n";
	string action;

	while (true)
	{
		//Getting user input
		getline(cin, action);

		if (!action.empty()) {

			//Lowercasing input to improve the comparison
			transform(action.begin(), action.end(), action.begin(), ::tolower);

			//Removing empty spaces and separate words
			istringstream buffer(action);
			vector<string> tokens{ istream_iterator<string>{buffer}, istream_iterator<string>{} };

			//Stop playing
			if (tokens[0] == "quit" || tokens[0] == "leave" || tokens[0] == "exit")
			{
				cout << "Good Bye!!";
				break;
			}

			if (!ExecuteAction(tokens))
			{
				cout << "Incorrect command\n";
			}
		}
		else {
			cout << "Write something\n";
		}
	}
}

bool World::ExecuteAction(vector<string>& action)
{
	if (action.size() == 0)
	{
		return false;
	}
	else
	{
				
		if (!pPlayer->PerformAction(action))
		{
			return false;
		}

		cout << "\n\n";
		
		return true;
	}
}