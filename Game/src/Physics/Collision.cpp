#include "Collision.h"
#include "Math.h"
#include <math.h>

bool Collision::IsColliding(const sf::FloatRect& player, const sf::FloatRect& target, sf::Vector2f& outVelocity, Type type /*= Type::Circle*/)
{
	switch (type)
	{
	case Type::Circle:
		return IsColliding_Circle(player, target, outVelocity);
	case Type::Square:
		return false;
	}

	return false;
}

bool Collision::IsColliding_Circle(const sf::FloatRect& player, const sf::FloatRect& target, sf::Vector2f& outVelocity)
{
	const sf::Vector2f toTarget = target.getPosition() - player.getPosition();
	const sf::FloatRect playerRect = Math::GetScaledRect(player);
	const sf::FloatRect targetRect = Math::GetScaledRect(target);
	const float radius = Math::GetRadius(playerRect, targetRect);
	const float distance = Math::GetVectorLength(toTarget);

	if (distance < radius)
	{
		const float overlappedDistance = (radius - distance);
		outVelocity = -Math::GetNormalizedVector(toTarget) * overlappedDistance;
		return true;
	}

	return false;
}



