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


string Entity::GetName()
{
	return m_Name;
}


string Entity::GetDescription()
{
	return m_Description;
}


void Entity::AddEntity(Entity* entity)
{
	m_Contains.push_back(entity);
} 