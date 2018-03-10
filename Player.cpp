#include "Player.h"


Player::Player(string name, string description, Room* room) :Entity(name, description)
{
	m_Type = PLAYER;
	m_Location = room;
}


bool Player::PerformAction(vector<string>& action)
{
	if (action[0] == "look")
	{
		m_Location->Look();
		return true;
	} 
	else
	{
		return false;
	}
}