#include "World.h"
#include "Exit.h"
#include "Item.h"


World::World()
{
	PrepareEntitiesForNewGame();
}


void World::Run()
{
	AddIntroduction();

	string action;
	pPlayer->PerformAction(vector<string>{"look"});
	cout << "\n\n";
	
	while (true)
	{
		//Check if playing or player has lost/won
		if (!m_Playing)
		{
			cout << "Do you want to play again? Yes or no?\n"; 
		
			while (true)
			{
				getline(cin, action);
				auto& tokens = GetTokens(action);
				if (tokens[0] == "yes" || tokens[0] == "y")
				{
					cout << "\n\n";
					RestartGame();
					AddIntroduction();
					break;
				}
				else if (tokens[0] == "no" || tokens[0] == "n")
				{
					cout << "Good Bye!!";
					return;
				}
			}
		}

		//Getting user input
		cout << "-- " << m_NumberOfTurnsPlayed << "/" << MAX_NUMBER_OF_TURNS <<" actions\n";
		cout << ">";
		getline(cin, action);

		if (!action.empty()) 
		{
			auto& tokens = GetTokens(action);

			//Stop playing
			if (tokens[0] == "quit" || tokens[0] == "leave" || tokens[0] == "exit")
			{
				cout << "Good Bye!!";
				break;
			}

			if (tokens.size() > 0)
			{
				bool finish = pPlayer->PerformAction(tokens);
				cout << "\n\n";

				if (finish)
				{
					cout << "             CONGRATULATIONS\n";
					cout << "               YOU WIN!!!!\n\n";
					m_Playing = false;
				}
			}
		}
		else
		{
			cout << "Write something\n";
		}

		m_NumberOfTurnsPlayed++;

		if (m_NumberOfTurnsPlayed >= MAX_NUMBER_OF_TURNS && m_Playing)
		{
			m_Playing = false;
			cout << "You have run out of time!! What a mess!!\n\nYOU LOSE\n\n";
		}
	}
}


//Private methods


void World::RestartGame()
{
	m_NumberOfTurnsPlayed = 0;
	m_Playing = true;
	PrepareEntitiesForNewGame();
}


vector<string> World::GetTokens(string action)
{
	//Lowercasing input to improve the comparison
	transform(action.begin(), action.end(), action.begin(), ::tolower);

	//Removing empty spaces and separate words
	istringstream buffer(action);
	vector<string> tokens{ istream_iterator<string>{buffer}, istream_iterator<string>{} };

	return tokens;
}


void World::PrepareEntitiesForNewGame()
{
	m_Entities.clear();

	//Rooms
	Room* pEntrance = new Room("Entrance", "Empty room with one chair");
	Room* pLivingRoom = new Room("Living Room", "Big living room with a table with 4 chairs, one TV and a couch");
	Room* pBedroom = new Room("Bedroom", "Small bedroom with a bed and a chair");
	Room* pBathroom = new Room("Bathroom", "Very small bathroom with toilet");
	Room* pKitchen = new Room("Kitchen", "There is a fridge and an oven");
	Room* pBasement = new Room("Basement", "It's very cold");

	m_Entities.push_back(pEntrance);
	m_Entities.push_back(pLivingRoom);
	m_Entities.push_back(pBedroom);
	m_Entities.push_back(pBathroom);
	m_Entities.push_back(pKitchen);
	m_Entities.push_back(pBasement);

	//Exits
	Exit* pExit = new Exit("door", "made of wood", NORTH, pEntrance, pLivingRoom, false, true, true);
	Exit* pExit2 = new Exit("passage", "", WEST, pLivingRoom, pBedroom, true, false, false);
	Exit* pExit3 = new Exit("door", "made of plastic", NORTH, pBedroom, pBathroom, false, true, true);
	Exit* pExit4 = new Exit("corridor", "", EAST, pLivingRoom, pKitchen, true, false, false);
	Exit* pExit5 = new Exit("stairs", "", NORTH, pLivingRoom, pBasement, true, false, false);

	m_Entities.push_back(pExit);
	m_Entities.push_back(pExit2);
	m_Entities.push_back(pExit3);
	m_Entities.push_back(pExit4);
	m_Entities.push_back(pExit5);

	//Items
	Item* pBox = new Item("box", "made of steel", pEntrance, NULL, true, false, NULL, true);
	Item* pBottle = new Item("bottle", "full of water", pLivingRoom, NULL, true, false, NULL, true);
	Item* pKey = new Item("key", "of the main door", NULL, pBox, false, false, pExit, true);
	Item* pOven = new Item("oven", "that is very old", pKitchen, NULL, true, false, NULL, false);
	Item* pFridge = new Item("fridge", "white as snow", pKitchen, NULL, true, false, NULL, false);
	Item* pBread = new Item("sandwich", "very nutritional", NULL, pFridge, false, false, NULL, true);
	Item* pPassword = new Item("password", "written in a paper", NULL, pOven, false, false, pExit3, true);
	Item* pPaper = new Item("paper", "that you can use for... well, you know... In the bathroom", pBasement, NULL, false, false, NULL, true);
	Item* pCloset = new Item("closet", "full of clothes", pBedroom, NULL, true, true, NULL, false);
	Item* pToilet = new Item("toilet", "that you need in urgency", pBathroom, NULL, true, false, NULL, false);


	m_Entities.push_back(pBox);
	m_Entities.push_back(pBottle);
	m_Entities.push_back(pKey);
	m_Entities.push_back(pOven);
	m_Entities.push_back(pFridge);
	m_Entities.push_back(pBread);
	m_Entities.push_back(pPassword);
	m_Entities.push_back(pPaper);
	m_Entities.push_back(pCloset);
	m_Entities.push_back(pToilet);

	//Player
	pPlayer = new Player("Pepe", "I have a bath urge", pEntrance);

	m_Entities.push_back(pPlayer);
}


void World::AddIntroduction()
{
	cout << "Welcome to 'I have a bath urge' Zork\n\n";
	cout << "You have arrived home after a hard day's work and you have to go to the bathroom urgently.\n";
	cout << "You have to find toilet paper and get to the toilet before you can not take it anymore!!\n\n";
}