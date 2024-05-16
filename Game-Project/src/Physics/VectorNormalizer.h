#pragma once
#include "SFML/Graphics.hpp"

struct Normalize
{
	Normalize();
	sf::Vector2f GetUnit(sf::Vector2f& starting, sf::Vector2f& target);
};