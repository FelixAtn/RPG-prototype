#include "Physics/Math.h"

sf::Vector2f Math::GetUnitVector(sf::Sprite& starting, sf::Sprite& target)
{
	return GetNormalizedVector(target.getPosition() - starting.getPosition());
}

sf::Vector2f Math::GetNormalizedVector(const sf::Vector2f& vector)
{
	const float inverseLength = 1.0f / GetVectorLength(vector);
	return sf::Vector2f
	{
		vector.x * inverseLength,
		vector.y * inverseLength
	};
}

float Math::GetVectorLength(const sf::Vector2f& vector)
{
	return std::sqrt(GetVectorLengthSquared(vector));
}

float Math::GetVectorLengthSquared(const sf::Vector2f& vector)
{
	return vector.x * vector.x + vector.y * vector.y;
}

const float Math::GetRadius(sf::FloatRect player, sf::FloatRect target)
{
	return GetRadius(player) + GetRadius(target);
}

const float Math::GetRadius(sf::FloatRect rect)
{
	return std::hypotf(rect.width, rect.width) * 0.5f;
}

sf::FloatRect Math::GetScaledRect(sf::FloatRect rect, float scale)
{
	sf::FloatRect result;
	float width = rect.width * scale;
	float height = rect.height * scale;
	float deltaHalfWidth = (result.width - width) * 0.5f;
	float deltaHalfHeight = (result.height - width) * 0.5f;

	result.left = rect.left + deltaHalfWidth;
	result.width = width - deltaHalfWidth;
	result.top = rect.top + deltaHalfHeight;
	result.height = height - deltaHalfHeight;

	return result;
}