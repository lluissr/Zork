#include "World.h"
#include "Exit.h"
#include "Item.h"


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
	Exit* pExit = new Exit("door", "made of wood", NORTH, pEntrance, pLivingRoom, false, false, true);
	Exit* pExit2 = new Exit("passage", "", WEST, pLivingRoom, pKitchen, true, false, false);
	
	entities.push_back(pExit);
	entities.push_back(pExit2);

	//Items
	Item* pBox = new Item("box", "made of steel", pKitchen, NULL, true, false);
	Item* pBread = new Item("bread", "very nutritional", NULL, pBox, false, false);
	Item* pBottle = new Item("bottle", "full of water", pLivingRoom, NULL, true, false);
	Item* pKey = new Item("key", "", pEntrance, NULL, false, false);

	entities.push_back(pBox);
	entities.push_back(pBread);
	entities.push_back(pBottle);
	entities.push_back(pKey);

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
		cout << ">";
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

			ExecuteAction(tokens);
		}
		else {
			cout << "Write something\n";
		}
	}
}

void World::ExecuteAction(vector<string>& action)
{
	if (action.size() > 0)
	{
		pPlayer->PerformAction(action);
		cout << "\n\n";
	}
}