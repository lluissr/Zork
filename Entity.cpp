#include "Entity.h"


Entity::Entity(const string name, const string description)
{
	m_Name = name;
	m_Description = description;
}


EntityType Entity::GetType() const
{
	return m_Type;
}


string Entity::GetName() const
{
	return m_Name;
}


string Entity::GetDescription() const
{
	return m_Description;
}


void Entity::AddEntity(Entity* entity)
{
	m_Contains.push_back(entity);
} 