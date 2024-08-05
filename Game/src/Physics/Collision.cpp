#include "Collision.h"
#include "VectorMath.h"
#include <math.h>

#pragma region AABB
void Collision::Rectangles::Reset()
{
	m_Velocity = { 0.f, 0.f };
}
bool Collision::Rectangles::IsColliding(const sf::Sprite& player, const sf::Sprite& target)
{
	sf::Vector2f playerPosition = player.getPosition();
	sf::Vector2f targetPosition = target.getPosition();
	sf::FloatRect playerRect = player.getLocalBounds();
	sf::FloatRect targetRect = target.getLocalBounds();

	const sf::Vector2f toTarget = targetPosition - playerPosition;
	m_Distance = VectorMath::Math::GetNormalizedVector(toTarget);

	const float hitBoxSize = 0.25f;
	const float playerCenterRect = (playerRect.width + playerRect.height) * hitBoxSize;
	const float targetCenterRect = (targetRect.width + targetRect.height) * hitBoxSize;

	float xOverlap = std::abs(toTarget.x) - playerCenterRect;
	float yOverlap = std::abs(toTarget.y) - targetCenterRect;
	m_Overlap = sf::Vector2f(xOverlap, yOverlap);

	return m_Overlap.x < 0.0f && m_Overlap.y < 0.0f;
}
sf::Vector2f Collision::Rectangles::GetVelocity()
{
	m_Overlap = sf::Vector2f(std::abs(m_Overlap.x), std::abs(m_Overlap.y));

	if (m_Overlap.x <= m_Overlap.y && m_Distance.x >= 0.0f)
	{
		m_Velocity = { -m_Overlap.x, 0.0f };   // clamp xMin		
	}
	else if (m_Overlap.x <= m_Overlap.y && m_Distance.x <= 0.0f)
	{
		m_Velocity = { m_Overlap.x, 0.0f };  // clamp xMax
	}
	else if (m_Overlap.y <= m_Overlap.x && m_Distance.y >= 0.0f)
	{
		m_Velocity = { 0.0f, -m_Overlap.y }; // clamp yMin
	}
	else if ((m_Overlap.y <= m_Overlap.x && m_Distance.y <= 0.0f))
	{
		m_Velocity = { 0.0f, m_Overlap.y }; // clamp xMax
	}
	else
	{
		m_Velocity = { 0, 0 };
	}

	return m_Velocity;
}
#pragma endregion

#pragma region CIRCLES
void Collision::Circles::Reset()
{
	m_Velocity = sf::Vector2f(0.f, 0.f);
}
bool Collision::Circles::IsColliding(const sf::Sprite& player, const sf::Sprite& target)
{
	const sf::Vector2f position = player.getPosition();
	const sf::Vector2f targetPosition = target.getPosition();
	const sf::Vector2f toTarget = targetPosition - position;
	const float distance = VectorMath::Math::GetVectorLength(toTarget);
	const float radius = GetRadius(player.getGlobalBounds(), target.getLocalBounds());

	if (distance < radius)
	{
		const float overlappedDistance = (radius - distance);
		m_Velocity = -VectorMath::Math::GetNormalizedVector(toTarget) * overlappedDistance;
		return true;
	}

	return false;
}
const float Collision::Circles::GetRadius(sf::FloatRect player, sf::FloatRect target) const
{
	const float radius = (player.width + player.height) * 0.25f;
	const float targetRadius = (target.width + target.height) * 0.25f;
	return radius + targetRadius;
}

sf::Vector2f Collision::Circles::GetVelocity()
{
	return m_Velocity;
}
#pragma endregion



// #include "CollisionManager.h"
// #include <cmath>
// #include "Physics/VectorNormalizer.h"
// 
// 
// void CollisionManager::Reset()
// {
// 	m_Velocity = sf::Vector2f(0.f, 0.f);
// }
// 
// bool CollisionManager::IsColliding(const sf::Sprite& player, const sf::Sprite& target)
// {
// 	const sf::Vector2f position = player.getPosition();
// 	const sf::Vector2f targetPosition = target.getPosition();
// 	const sf::Vector2f toTarget = targetPosition - position;
// 	const float distance = Physics::Math::GetVectorLength(toTarget);
// 	const float radius = GetRadius(player.getGlobalBounds(), target.getLocalBounds());
// 
// 	if (distance < radius)
// 	{
// 		const float overlappedDistance = (radius - distance);
// 		m_Velocity = -Physics::Math::GetNormalizedVector(toTarget) * overlappedDistance;
// 		return true;
// 	}
// 
// 	return false;
// // 	
// // 	sf::Vector2f spritePos = { spriteOne.getPosition().x, spriteOne.getPosition().y };
// // 	sf::Vector2f otherPos = { spriteTwo.getPosition().x, spriteTwo.getPosition().y };
// // 	sf::Vector2f half;
// // 	half = spriteOne.getGlobalBounds().getSize() / 2.f, spriteTwo.getGlobalBounds().getSize() / 2.f;
// // 	m_Distance = otherPos - spritePos;
// // 	m_Overlap = sf::Vector2f(std::abs(m_Distance.x) - half.x, std::abs(m_Distance.y) - half.y);
// // 	// Check the collision
// // 	return m_Overlap.x < 0.0f && m_Overlap.y < 0.0f;
// 	
// }
// 
// // sf::FloatRect CollisionManager::GetRadius(sf::FloatRect player, sf::FloatRect target)
// // {
// // 	
// // }
// 
// 
// const float CollisionManager::GetRadius(sf::FloatRect player, sf::FloatRect target) const
// {
// 	const float radius = (player.width + player.height) * 0.25f;
// 	const float targetRadius = (target.width + target.height) * 0.25f;
// 	return radius + targetRadius;
// }
// 
// sf::Vector2f CollisionManager::GetClampValue()
// {
// 	return m_Velocity;
// 	
// // 	m_Overlap = sf::Vector2f(std::abs(m_Overlap.x), std::abs(m_Overlap.y));
// // 	sf::Vector2f m_ClampValue;
// // 	if (m_Overlap.x <= m_Overlap.y && m_Distance.x >= 0.0f)
// // 	{
// // 		m_ClampValue = { -m_Overlap.x, 0.0f };   // Clamp left		
// // 	}
// // 	else if (m_Overlap.x <= m_Overlap.y && m_Distance.x <= 0.0f)
// // 	{
// // 		m_ClampValue = { m_Overlap.x, 0.0f };  // Clamp right
// // 	}
// // 	else if (m_Overlap.y <= m_Overlap.x && m_Distance.y >= 0.0f)
// // 	{
// // 		m_ClampValue = { 0.0f, -m_Overlap.y };
// // 	}
// // 	else if ((m_Overlap.y <= m_Overlap.x && m_Distance.y <= 0.0f))
// // 	{
// // 		m_ClampValue = { 0.0f, m_Overlap.y };
// // 	}
// // 	else
// // 	{
// // 		m_ClampValue = { 0, 0 };
// // 	}
// // 	return m_ClampValue;
// 	
// }

