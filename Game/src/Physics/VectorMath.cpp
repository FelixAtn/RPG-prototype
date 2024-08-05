#include "Physics/VectorMath.h"

sf::Vector2f VectorMath::VectorNormalizer::GetUnitVector(sf::Sprite& starting, sf::Sprite& target)
{
	return VectorMath::Math::GetNormalizedVector(target.getPosition() - starting.getPosition());
}

float VectorMath::Math::GetVectorLengthSquared(const sf::Vector2f& vector)
{
	return vector.x * vector.x + vector.y * vector.y;
}

float VectorMath::Math::GetVectorLength(const sf::Vector2f& vector)
{
	return std::sqrt(GetVectorLengthSquared(vector));
}

sf::Vector2f VectorMath::Math::GetNormalizedVector(const sf::Vector2f& vector)
{
	const float inverseLength = 1.0f / GetVectorLength(vector);
	return sf::Vector2f
	{
		vector.x * inverseLength,
		vector.y * inverseLength
	};
}