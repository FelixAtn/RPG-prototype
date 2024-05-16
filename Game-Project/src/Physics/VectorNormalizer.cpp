#include "Physics/VectorNormalizer.h"

Normalize::Normalize()
{

}

sf::Vector2f Normalize::GetUnit(sf::Vector2f& starting, sf::Vector2f& target)
 {
	sf::Vector2f deltaPosition = target - starting;
	sf::Vector2f direction;

	float lenght = std::sqrt(deltaPosition.x * deltaPosition.x + deltaPosition.y * deltaPosition.y);
		direction.x = deltaPosition.x / lenght;
		direction.y = deltaPosition.y / lenght;
	
	return direction;
 }

