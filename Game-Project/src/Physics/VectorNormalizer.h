#pragma once
#include "SFML/Graphics.hpp"

struct Normalize
{
 sf::Vector2f GetDirectionUnit(sf::Vector2f starting, sf::Vector2f target) const;
};