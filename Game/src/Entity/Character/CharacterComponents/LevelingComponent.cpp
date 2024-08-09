#include "LevelingComponent.h"

LevelingComponent::LevelingComponent()
{
	m_Level = 0;
	m_Experience = 0;
}

int LevelingComponent::GetLevel() const
{
	return m_Level;
}

int LevelingComponent::GetExp() const
{
	return m_Experience;
}

void LevelingComponent::SetLevel(int level)
{
	m_Level = level;
}

void LevelingComponent::SetExp(int experience)
{
	m_Experience = experience;
}
