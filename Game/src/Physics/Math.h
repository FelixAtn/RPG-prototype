#pragma once
#include "SFML/Graphics.hpp"

namespace Math
{
	sf::Vector2f GetUnitVector(sf::Sprite& starting, sf::Sprite& target);
	sf::Vector2f GetNormalizedVector(const sf::Vector2f& vector);
	float GetVectorLengthSquared(const sf::Vector2f& vector);
	float GetVectorLength(const sf::Vector2f& vector);
	const float GetRadius(sf::FloatRect player, sf::FloatRect target);
	const float GetRadius(sf::FloatRect rect);
	sf::FloatRect GetScaledRect(sf::FloatRect rect, float scale = 0.6f);
};