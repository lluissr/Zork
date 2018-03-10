#include "World.h"


World::World()
{
	//TODO
}


void World::Run()
{
	cout << "Welcome to Zork\n";
	string command;

	while (true)
	{
		//Getting user input
		getline(cin, command);

		if (!command.empty()) {

			//Lowercasing input to improve the comparison
			transform(command.begin(), command.end(), command.begin(), ::tolower);

			//Removing empty spaces and separate words
			istringstream buffer(command);
			vector<string> tokens{ istream_iterator<string>{buffer}, istream_iterator<string>{} };

			//Stop playing
			if (tokens[0] == "quit" || tokens[0] == "leave")
			{
				cout << "Good Bye!!";
				break;
			}

			if (!ExecuteCommand(tokens))
			{
				cout << "Incorrect command\n";
			}
		}
		else {
			cout << "Write something\n";
		}
	}
}

bool World::ExecuteCommand(vector<string>& command)
{
	if (command.size() == 0)
	{
		return false;
	}
	else
	{
		cout << "Correct command: Execute " << command[0] << "\n";
		return true;
	}
}