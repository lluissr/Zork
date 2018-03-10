#include "Entity.h"


Entity::Entity(string name, string description)
{
	m_Name = name;
	m_Description = description;
}


EntityType Entity::GetType()
{
	return m_Type;
}