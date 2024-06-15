#include "CollisionManager.h"
#include <iostream>

bool CollisionManager::IsColliding(sf::Sprite& spriteOne, sf::Sprite& spriteTwo)
{
	sf::Vector2f spritePos = {spriteOne.getPosition().x, spriteOne.getPosition().y };
	sf::Vector2f otherPos = { spriteTwo.getPosition().x, spriteTwo.getPosition().y };

	m_Half = spriteOne.getGlobalBounds().getSize() / 2.f, spriteTwo.getGlobalBounds().getSize() / 2.f;
	m_Distance = otherPos - spritePos;
	m_Overlap = sf::Vector2f(std::abs(m_Distance.x) - m_Half.x, std::abs(m_Distance.y) - m_Half.y);

	// Check the collision
	return m_Overlap.x <= 0.0f && m_Overlap.y <= 0.0f;
}

// Mininum Translation Vector (MTV)
sf::Vector2f CollisionManager::GetClampValue() 
{
	m_Overlap = sf::Vector2f(std::abs(m_Overlap.x), std::abs(m_Overlap.y));

	if (m_Overlap.x <= m_Overlap.y && m_Distance.x >= 0.0f)
	{
		m_ClampValue = { -m_Overlap.x, 0.0f };   // Clamp left		
	}
	else if (m_Overlap.x <= m_Overlap.y && m_Distance.x <= 0.0f)
	{
		m_ClampValue = { m_Overlap.x, 0.0f };  // Clamp right
	}
	else if (m_Overlap.y <= m_Overlap.x && m_Distance.y >= 0.0f)
	{
		m_ClampValue = { 0.0f, -m_Overlap.y };
	}
	else if ((m_Overlap.y <= m_Overlap.x && m_Distance.y <= 0.0f))
	{
		m_ClampValue = { 0.0f, m_Overlap.y };
	}
	else
	{
		m_ClampValue = { 0, 0 };
	}

	return m_ClampValue;
}
