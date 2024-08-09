#include "MovementComponent.h"
#include "Physics/VectorMath.h"


MovementComponent::MovementComponent()
{
	sf::Vector2f m_MovementDirection = { 0.f, 0.f };
	sf::Vector2f m_Velocity = { 0.f, 0.f };
	float m_MovementSpeed = 0.f;
	bool IsWalking = false;
}

sf::Vector2f MovementComponent::GetVelocity() const
{
	return m_Velocity;
}

float MovementComponent::GetMovementSpeed() const
{
	return m_MovementSpeed;
}

sf::Vector2f MovementComponent::GetMovementDirection() const
{
	return m_MovementDirection;
}

void MovementComponent::SetMovementSpeed(float speed)
{
	m_MovementSpeed = speed;
}

void MovementComponent::SetMovementDirection(sf::Vector2f movementDirection)
{
	m_MovementDirection = movementDirection;
}

void MovementComponent::SetVelocity(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}

void MovementComponent::Move(sf::Sprite& character, float deltaTime)
{
	VectorMath::Math::GetNormalizedVector(m_MovementDirection);
	sf::Vector2f direction = GetMovementDirection();
	sf::Vector2f position = GetCharacterPosition(character);
	sf::Vector2f newPosition = GetNewPosition(position, deltaTime);
	character.setPosition(newPosition);
	m_Velocity = { 0.f, 0.f };
}

sf::Vector2f MovementComponent::GetCharacterPosition(sf::Sprite& character) const
{
	return character.getPosition();
}

sf::Vector2f MovementComponent::GetNewPosition(sf::Vector2f oldCharacterPosition, float deltaTime) const
{
	oldCharacterPosition += m_MovementDirection * m_MovementSpeed * deltaTime;
	return oldCharacterPosition + m_Velocity;
}

