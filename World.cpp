#include "World.h"
#include "Exit.h"

World::World()
{

	//Rooms
	Room* pEntrance = new Room("Entrance", "Empty room with one chair");
	Room* pLivingRoom = new Room("Living Room", "Big living room with a table with 4 chairs, one TV and a couch");
	Room* pKitchen = new Room("Kitchen", "Small room with a fridge and an oven");

	entities.push_back(pEntrance);
	entities.push_back(pLivingRoom);
	entities.push_back(pKitchen);

	//Exits
	Exit* pExit = new Exit("Door", "made of wood", NORTH, pEntrance, pLivingRoom, false);
	Exit* pExit2 = new Exit("Door", "made of plastic", WEST, pLivingRoom, pKitchen, false);
	
	entities.push_back(pExit);
	entities.push_back(pExit2);

	//Player
	pPlayer = new Player("Pepe", "Person", pEntrance);

	entities.push_back(pPlayer);
}


void World::Run()
{
	cout << "Welcome to Zork\n\n";
	string action;

	pPlayer->PerformAction(vector<string>{"look"});
	cout << "\n\n";

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