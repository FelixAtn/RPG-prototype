#include "Physics/VectorNormalizer.h"


 sf::Vector2f Normalize::GetDirectionUnit(sf::Vector2f starting, sf::Vector2f target) const
{
	sf::Vector2f direction;
	sf::Vector2f deltaPosition = target - starting;
	float lenght = std::sqrt(deltaPosition.x * deltaPosition.x) + (deltaPosition.y * deltaPosition.y);

		if(direction.x == 0 || direction.y == 0)
		{
			direction.x = deltaPosition.x / lenght;
			direction.y = deltaPosition.y / lenght;
		}
		return direction;
}
