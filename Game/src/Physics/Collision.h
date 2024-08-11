#pragma once
#include "SFML/Graphics.hpp"


struct Collision
{
	enum Type
	{
		Circle,
		Square
	};

	static bool IsColliding(const sf::FloatRect& player, const sf::FloatRect& target, sf::Vector2f& outVelocity, Type type = Type::Circle);

private:
	static bool IsColliding_Circle(const sf::FloatRect& player, const sf::FloatRect& target, sf::Vector2f& outVelocity);
};

