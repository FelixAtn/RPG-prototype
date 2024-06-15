#pragma once
#include "SFML/Graphics.hpp"

class CollisionManager
{
public:
	bool IsColliding(sf::Sprite& sprite, sf::Sprite& otherSprite);
	sf::Vector2f GetClampValue();

private:	
	sf::Vector2f m_Distance;
	sf::Vector2f m_Half;
	sf::Vector2f m_Overlap;
	sf::Vector2f m_ClampValue;
};

