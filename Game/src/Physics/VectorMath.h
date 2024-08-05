#pragma once
#include "SFML/Graphics.hpp"

namespace VectorMath
{
	class VectorNormalizer
	{
	public:
		static sf::Vector2f GetUnitVector(sf::Sprite& starting, sf::Sprite& target);
	};

	namespace Math
	{
		float GetVectorLengthSquared(const sf::Vector2f& vector);
		float GetVectorLength(const sf::Vector2f& vector);
		sf::Vector2f GetNormalizedVector(const sf::Vector2f& vector);
		//float GetRadius(sf::FloatRect player, sf::FloatRect target);
	};
}