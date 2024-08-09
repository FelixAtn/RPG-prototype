#include "HealthComponent.h"

void HealthComponent::SetHealth(int health)
{
	m_Health = health;
}

int HealthComponent::GetHealth() const
{
	return m_Health;
}

void HealthComponent::IncreaseHealth(int amount)
{
	m_Health += amount;
}

void HealthComponent::DecreaseHealth(int amount)
{
	if(IsAlive())
	{
		m_Health -= amount;
	}
}

bool HealthComponent::IsAlive() const
{
	if(m_Health > 0)
	{
		return true;
	}
	return false;
}
