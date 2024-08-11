#pragma once
#include "SFML/Graphics.hpp"

class Character;
class Sprite;

class MovementComponent
{
public:
	MovementComponent();
	sf::Vector2f GetVelocity() const;
	float GetMovementSpeed() const;
	sf::Vector2f GetMovementDirection() const;

	void SetVelocity(sf::Vector2f velocity);
	void SetMovementSpeed(float speed);
	void SetMovementDirection(sf::Vector2f movementDirection);
	void Move(sf::Sprite& character, float deltaTime);

private:
	sf::Vector2f GetCharacterPosition(sf::Sprite& character) const;
	sf::Vector2f GetNewPosition(sf::Vector2f normalizedDirection, float deltaTime) const;

private:
	sf::Vector2f m_MovementDirection;
	sf::Vector2f m_Velocity;
	float m_MovementSpeed;
	bool IsWalking;
};

